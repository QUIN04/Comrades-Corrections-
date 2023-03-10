. . .

dishRouter.route('/')
.get((req,res,next) => {
    Dishes.find({})
    .populate('comments.author')
    .then((dishes) => {
        res.statusCode = 200;
        res.setHeader('Content-Type', 'application/json');
        res.json(dishes);
    }, (err) => next(err))
    .catch((err) => next(err));
})

. . .

dishRouter.route('/:dishId')
.get((req,res,next) => {
    Dishes.findById(req.params.dishId)
    .populate('comments.author')
    .then((dish) => {
        res.statusCode = 200;
        res.setHeader('Content-Type', 'application/json');
        res.json(dish);
      }, (err) => next(err))
      .catch((err) => next(err));
  })
  
  . . .
  
  dishRouter.route('/:dishId/comments')
  .get((req,res,next) => {
      Dishes.findById(req.params.dishId)
      .populate('comments.author')
      .then((dish) => {
          if (dish != null) {
              res.statusCode = 200;
              res.setHeader('Content-Type', 'application/json');
              res.json(dish.comments);
          }
          else {
              err = new Error('Dish ' + req.params.dishId + ' not found');
              err.status = 404;
              return next(err);
          }
      }, (err) => next(err))
      .catch((err) => next(err));
    })
    .post(authenticate.verifyUser, (req, res, next) => {
        Dishes.findById(req.params.dishId)
        .then((dish) => {
            if (dish != null) {
                req.body.author = req.user._id;
                dish.comments.push(req.body);
                dish.save()
                .then((dish) => {
                    Dishes.findById(dish._id)
                    .populate('comments.author')
                    .then((dish) => {
                        res.statusCode = 200;
                        res.setHeader('Content-Type', 'application/json');
                        res.json(dish);
                    })            
                }, (err) => next(err));
            }
            else {
                err = new Error('Dish ' + req.params.dishId + ' not found');
                err.status = 404;
                return next(err);
                .catch((err) => next(err));
              })
              .post(authenticate.verifyUser, (req, res, next) => {
                  Dishes.findById(req.params.dishId)
                  .then((dish) => {
                      if (dish != null) {
                          req.body.author = req.user._id;
                          dish.comments.push(req.body);
                          dish.save()
                          .then((dish) => {
                              Dishes.findById(dish._id)
                              .populate('comments.author')
                              .then((dish) => {
                                  res.statusCode = 200;
                                  res.setHeader('Content-Type', 'application/json');
                                  res.json(dish);
                              })            
                          }, (err) => next(err));
                      }
                      else {
                          err = new Error('Dish ' + req.params.dishId + ' not found');
                          err.status = 404;
                          return next(err);
                        }
                      }, (err) => next(err))
                      .catch((err) => next(err));
                  })
                  
                  . . .
                  
                  .put(cors.corsWithOptions, authenticate.verifyUser, (req, res, next) => {
                      Dishes.findById(req.params.dishId)
                      .then((dish) => {
                          if (dish != null && dish.comments.id(req.params.commentId) != null) {
                              if (req.body.rating) {
                                  dish.comments.id(req.params.commentId).rating = req.body.rating;
                              }
                              if (req.body.comment) {
                                  dish.comments.id(req.params.commentId).comment = req.body.comment;                
                              }
                              dish.save()
                              .then((dish) => {
                                  Dishes.findById(dish._id)
                                  .populate('comments.author')
                                  .then((dish) => {
                                    res.statusCode = 200;
                    res.setHeader('Content-Type', 'application/json');
                    res.json(dish);  
                })              
            }, (err) => next(err));
        }
        else if (dish == null) {
            err = new Error('Dish ' + req.params.dishId + ' not found');
            err.status = 404;
            return next(err);
        }
        else {
            err = new Error('Comment ' + req.params.commentId + ' not found');
            err.status = 404;
            return next(err);            
        }
    }, (err) => next(err))
    .catch((err) => next(err));
})
.delete(cors.corsWithOptions, authenticate.verifyUser, (req, res, next) => {
    Dishes.findById(req.params.dishId)
    .then((dish) => {
        if (dish != null && dish.comments.id(req.params.commentId) != null) {
          dish.comments.id(req.params.commentId).remove();
            dish.save()
            .then((dish) => {
                Dishes.findById(dish._id)
                .populate('comments.author')
                .then((dish) => {
                    res.statusCode = 200;
                    res.setHeader('Content-Type', 'application/json');
                    res.json(dish);  
                })               
            }, (err) => next(err));
        }
        else if (dish == null) {
            err = new Error('Dish ' + req.params.dishId + ' not found');
            err.status = 404;
            return next(err);
        }
        else {
            err = new Error('Comment ' + req.params.commentId + ' not found');
            err.status = 404;
            return next(err);            
        }
    }, (err) => next(err))
  })
