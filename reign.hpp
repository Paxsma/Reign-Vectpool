#include <vector>

namespace reign {

      template <typename t>
      class allocate {

          public:

            explicit allocate(const std::uint32_t initial_size = 0u) {
                  this->allocs.reserve(initial_size);
                  return;
            }

            template <typename... Args>
            t *make_alloc(Args &&...args) {
                  this->ensure_capacity();
                  this->allocs.emplace_back(std::forward<Args>(args)...);
                  return &this->allocs.back();
            }

            inline void free() {
                  this->allocs.clear();
                  return;
            }

          private:
            std::vector<t> allocs;

            inline void ensure_capacity() {
                  if (this->allocs.size() == this->allocs.capacity()) {
                        this->allocs.reserve(this->allocs.capacity() * 2u);
                  }
                  return;
            }
      };
} // namespace reign
