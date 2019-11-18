//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "fecr01TestApp.h"
#include "fecr01App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<fecr01TestApp>()
{
  InputParameters params = validParams<fecr01App>();
  return params;
}

fecr01TestApp::fecr01TestApp(InputParameters parameters) : MooseApp(parameters)
{
  fecr01TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

fecr01TestApp::~fecr01TestApp() {}

void
fecr01TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  fecr01App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"fecr01TestApp"});
    Registry::registerActionsTo(af, {"fecr01TestApp"});
  }
}

void
fecr01TestApp::registerApps()
{
  registerApp(fecr01App);
  registerApp(fecr01TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
fecr01TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fecr01TestApp::registerAll(f, af, s);
}
extern "C" void
fecr01TestApp__registerApps()
{
  fecr01TestApp::registerApps();
}
