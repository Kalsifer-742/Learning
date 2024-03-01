# Lecture 29/02/24

## Data

- Acquisition
- Preprocessing
- Dimensionality reduction
  - filtering for only interesting features
 
## Learning

- Model learning
- Model testing
  - using different data
 
Iteration is key

Information gap when extracting features from the data

## Types of learning

### Supervised
- Classification 
  - finite set of labels 
  - Face recognition
- Regression
  - label is real-valued
  - predict value of a stock
- Ranking
  - label is ranking
  - web pages ranking

Recap:
- Classification:
  - Classification categorizes input data into predefined classes or
  categories.
- Regression:
  - Regression predicts continuous numerical values based on input
  features.
- Ranking:
  - Ranking orders a set of items based on their relevance or preference.
 
### Unsupervised

- Clustering
  - Social newtwork analysis 
  - Anomaly detection. find the outlier
- dimensionality reduction
  -  mapping data into another low dimensional space 

Recap:
- Clustering
  - Clustering groups similar data points into clusters or groups
    based on their inherent characteristics or features.
- Dimensionality Reduction
  - Dimensionality reduction reduces the number of input variables
    or features in a dataset while preserving the most important
    information.

### Reinforcment Learning

Learn to play games

an agent learns from the environment by interacting with it and
receiving rewards for performing actions

> if we have enough data we can also do:

#### semi-supervised
#### active learning

## Data collection

### Batch or Offline
  - model learn from entire data set
  - new model has to be retrained with new data to improve
  - dataset is not too huge
### Online
  - model learns from new data
  - model adapts to changes
  - data processed in real time and computational resources are limited

---

## Classification part 2

Why it all works? It's tanks to generalization
Generalization is key. A model needs to be able to do that.
Example:

| label | features |
| --- | --- |
_apple_ | **red** - **round** - leaf - 3oz,
_apple_ | green - **round** - **no leaf** - **4oz**

test: **red**, **round**, **no leaf**, **4oz** -> _apple_
