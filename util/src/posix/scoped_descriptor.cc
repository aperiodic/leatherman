#include <leatherman/util/posix/scoped_descriptor.hpp>

using namespace std;

namespace leatherman { namespace util { namespace posix {

    scoped_descriptor::scoped_descriptor(int descriptor) :
        scoped_resource(move(descriptor), close)
    {
    }

    void scoped_descriptor::close(int descriptor)
    {
        if (descriptor >= 0) {
            ::close(descriptor);
        }
    }

}}}  // namespace leatherman::util::posix
