    Advanced Coffee Makers
##
Problem
##
Advanced Coffee Makers (ACM) Company holds a large portion of the coffee vending machine market.
Facing with numerous variations of coffee machines that the market demands for, ACM tries to develop a
product line, so that each time a customer requests for a specific configuration of coffee machines, it can
easily produce and deliver the product in a shorter time and with lower cost. This way, if a customer asks
for example, for a coffee machine that serves both coffee and tea, but does not offer options for adding
cream to coffee, ACM can produce the corresponding machine including coffee and tea features, but not
having creamer features.

To this end, ACM has prepared a feature model of the coffee machine products. The feature model
contains a hierarchy of the features appearing in a coffee machine, organized as a rooted tree. The root
always corresponds to the whole coffee machine product, while other nodes represent the features of a
coffee machine. Relationships between a parent feature and its child features (or sub-features) are
categorized as:

  • Mandatory – child feature is required.
  
  • Optional – child feature is optional.
  
  • Or – at least one of the sub-features must be selected.
  
  • Alternative (xor) – one of the sub-features must be selected.
##
Having a feature model, a customer may ask for a specific configuration, i.e., a set of features. For
example, {Coffee Machine, Brewer, Coffee Maker, American, Creamer, Regular} form a valid
configuration. Note that all mandatory features (including the root) must be present in a valid
configuration. In contrast, the configuration {Coffee Machine, Brewer, Coffee Maker, Creamer, Regular,
Tea Maker} is not valid, since no sub-feature of Coffee Maker is selected. Note that the whole Coffee
Machine (the root) must be included in all valid configurations.
A valid configuration must include all mandatory features (including the root), must have at least one
from a set of features having ‘or’ relationship with their parents, and must have exactly one feature having‘xor’ relationship with their parents. Also, if a child is included in a valid configuration, its parent must
also be included.
Your program must input a feature model, together with a set of configurations, and for each configuration
determines whether the configuration is valid.
##
Input

The input consists of a number of test cases. Each test case has two parts. The first part represents the
feature model and the second part lists the configurations to be validated. The feature model is described
as a set of lines of the following forms, each describing a (non-leaf) feature F:

F = F1 + F2 + ... + Fn, where Fi is either a feature name, or a question mark followed by a feature name.

F = F1 | F2 | ... | Fn, where Fi is a feature name

F = F1 ^ F2 ^ ... ^ Fn, where Fi is a feature name

Each line defines the sub-features of a feature F. In the first case, optional features are preceded by a
question mark (see the sample input). It is assumed that the first line defines the whole coffee machine
(that must be present in all valid configurations). The feature names are sequences of upper- and lower-
case letters (with no blanks in between). However, there may be arbitrary number of blank characters in
the beginning or at the end of the lines, or around the symbols =, +, ?, |, and ^. You may safely assume
that each features is defined once, and the feature model forms a tree.
The last line of a feature model description comes a line containing a single # character, after which come
the lines describing the configurations that you must validate. Each configuration comes in a separate line
of the form {F1, F2, ..., Fn}, where Fi is a feature name, and n > 0. You may assume that each Fi has
appeared in the feature model description. The last line of the test case is a single line containing ##.
##
Output

For each configuration in each test case, print one line in the output containing either Valid or Invalid
words, indicating whether the corresponding configuration is valid. Print a line containing ## after the
output for each test case.
##
Sample Input

2

CoffeeMachine = Brewer + CoffeeMaker + Creamer + ?TeaMaker

CoffeeMaker = American | Espresso

Creamer = Regular ^ Irish

\#

{CoffeeMachine, Brewer, CoffeeMaker, American, Creamer, Regular}

{CoffeeMachine, Brewer, CoffeeMaker, Creamer, Regular, TeaMaker}

\#\#

A=?B+?C

B=D|E

\#

{A,B,C,D,E}

{A,D}

\#\#

Valid

Invalid

\#\#

Valid

Invalid

\#\#
