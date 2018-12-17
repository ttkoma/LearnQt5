import QtQuick 2.12
import QtTest 1.0
import Cm 1.0 as Cm

TestCase {
    name: "ClientTests"

    function initTestCase() { }

    function cleanupTestCase() { }

    function test_MasterControllerWelcomeMessage() {

        var welcomeMsg = masterController.ui_welcomeMessage;
        compare(welcomeMsg,
                "Welcome to Client Management app!", "ui_welcomeMessage")

        //verify(welcomeMsg === "", "welcome msg not a Empty string")
    }

    function test_NavigationController() {
        var navController = masterController.ui_navigationController;
        verify(navController !== null)
    }

//    function test_case1() {
//        compare(1 + 1, 2, "sanity check");
//        verify(true);
//    }
}
