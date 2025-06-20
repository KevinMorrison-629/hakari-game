#pragma once

#include <array>
#include <cstdint>
#include <iomanip>
#include <random>
#include <sstream>
#include <string>

/// @brief Project Namespace
namespace Hakari
{
    /// @brief Subproject Namespace
    namespace Core
    {

        /// @brief A 128-bit Universally Unique Identifier (UUID), conforming to RFC 4122 version 4.
        struct UUID
        {
        public:
            /// @brief Default constructor, initializes to a nil UUID (all zeros).
            UUID() : bytes{} {} // Zero-initialize the array

            /// @brief Generates a random UUID (version 4).
            /// This method uses a random number generator to create a 128-bit UUID,
            /// then sets the version and variant bits according to RFC 4122.
            /// @return A randomly generated UUID.
            static UUID generate()
            {
                UUID uuid;
                std::random_device rd;
                std::mt19937_64 gen(rd());
                std::uniform_int_distribution<uint64_t> dis;

                uint64_t high = dis(gen);
                uint64_t low = dis(gen);

                std::memcpy(uuid.bytes.data(), &high, sizeof(uint64_t));
                std::memcpy(uuid.bytes.data() + sizeof(uint64_t), &low, sizeof(uint64_t));

                // Set version (4) and variant (RFC 4122)
                uuid.bytes[6] = (uuid.bytes[6] & 0x0F) | 0x40; // version 4
                uuid.bytes[8] = (uuid.bytes[8] & 0x3F) | 0x80; // variant 1

                return uuid;
            }

            /// @brief Converts the UUID to a standard string representation.
            /// Format: 8-4-4-4-12 hexadecimal characters (e.g., "f47ac10b-58cc-4372-a567-0e02b2c3d479").
            /// @return A human-readable string representation of the UUID.
            std::string to_string() const
            {
                std::ostringstream oss;
                for (size_t i = 0; i < bytes.size(); ++i)
                {
                    if (i == 4 || i == 6 || i == 8 || i == 10)
                        oss << '-';
                    oss << std::hex << std::setw(2) << std::setfill('0') << (int)bytes[i];
                }
                return oss.str();
            }

            // Equality operators

            /// @brief UUID Equality comparison operator.
            /// @param other The UUID to compare with.
            /// @return true if UUIDs are identical, false otherwise.
            bool operator==(const UUID &other) const { return bytes == other.bytes; };

            /// @brief Inequality comparison operator.
            /// @param other The UUID to compare with.
            /// @return true if UUIDs are different, false otherwise.
            bool operator!=(const UUID &other) const { return !(*this == other); };

            /// @brief Less-than operator, useful for when UUID is used as a key in std::map.
            /// @param other The UUID to compare with.
            /// @return true if lhs if less than rhs, false otherwise.
            bool operator<(const UUID &other) const { return bytes < other.bytes; };

        private:
            /// @brief Stores the 128-bit UUID as 16 bytes.
            std::array<uint8_t, 16> bytes{};
        };

    } // namespace Core
} // namespace Hakari