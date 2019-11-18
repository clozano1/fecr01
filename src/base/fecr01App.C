#include "fecr01App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<fecr01App>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

fecr01App::fecr01App(InputParameters parameters) : MooseApp(parameters)
{
  fecr01App::registerAll(_factory, _action_factory, _syntax);
}

fecr01App::~fecr01App() {}

void
fecr01App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"fecr01App"});
  Registry::registerActionsTo(af, {"fecr01App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
fecr01App::registerApps()
{
  registerApp(fecr01App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
fecr01App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fecr01App::registerAll(f, af, s);
}
extern "C" void
fecr01App__registerApps()
{
  fecr01App::registerApps();
}
