Vasco
=====

Small machine learning library in C++ (a work very much in progress).

Some background to the theory at http://blog.jamild.com/post/77023959349/from-the-hessian-to-widrow-hoff-calculus-and-machine

## Use (Stochastic and Batch Gradient Descent)

First initialize a vector of type `VSSupervisedData*`. This will be your training set.

For each training example, initialize a `VSSupervisedData` instance dynamically with the desired number of features (this number should be consistent among one set):  
``VSSupervisedData *newData = new VSSupervisedData(num_features);``  
Then set the features by passing an array of type `float` to the method `setFeatures`:  
``newData->setFeatures(num_features, features);``
Finally, set the supervised training value -- the value that the model "should" result in. For a sigmoid hypothesis or any classification algorithm where there is a binary activation function, this value should be either 1 or 0.  
``newData->setSupervisedValue(target);``
Alternatively, you can call a constructor that does all this in one step:  
``VSSupervisedData *newData = new VSSupervisedData(num_features, features, target);``  

Now, create your hypothesis function. This is operating under the assumption that the output is a linear combination of the parameters and the features (i.e. sum of all the x-sub-i and theta-sub-i). For example, a sigmoid activation function would be like so:
``
float hyp(float y) {
  float h = 1 + exp(-1*y);
  h = 1 / h;
  return h;
}
``

Now, initialize the learner instance; either `VSStochasticLearner` or `VSBatchDescentLearner` -- `VSLearner` is an abstract data class. Include the number of parameters/features, the vector of `VSSupervisedData`s, and the desired learning rate.   
``VSStochasticLearner learner(num_features, training_set, learning_rate)``  

Then, simply call the update method of `VSLearner` (perhaps on another thread -- it can be very slow for large data sets or a large number of parameters). This should set the `_parameterValues` variable.  

To get a hypothesis for unknown/untrained data, just initialize a `VSData` instance in the same way as `VSSupervisedData`, except without the last argument:   
``VSData *newData = new VSData(num_features, features);``
and call `getHypothesisForData` from the learner instance:  
``learner.getHypothesisForData(newData);``

