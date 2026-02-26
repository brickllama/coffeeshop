module;

#include <gmock/gmock.h>

export module MockSteamer; /* Implementation Unit. */
import Steamer;

export class MockSteamer : public Steamer {
public:
  MOCK_METHOD(void, steam, (Liquid & liquid, double target_temperature),
              (override));
};
