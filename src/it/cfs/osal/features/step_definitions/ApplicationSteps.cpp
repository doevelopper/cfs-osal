

#include <cfs/osal/features/step_definitions/ApplicationSteps.hpp>

using cucumber::ScenarioScope;

// return to known state before every scenario
BEFORE()
{
}

GIVEN("^enabled$")
{
}

GIVEN("^disabled$")
{
}

THEN("^should be enabled$")
{
}

THEN("^should be disabled$")
{
}


GIVEN("^is created (.*)$")
{
    REGEX_PARAM(int, sensor_val);
}

WHEN("^created$")
{
}

THEN("^should be able to move to (.*)$")
{
    REGEX_PARAM(float, command);
}

THEN("^the (.*) should be activated with duty cycle (.*)$")
{
    REGEX_PARAM(std::string, solenoid);
    REGEX_PARAM(int, duty_cycle);
}

