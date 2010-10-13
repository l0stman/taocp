(define (fact n)
  (let iter ((i 1) (res 1))
    (if (> i n)
        res
        (iter (+ i 1) (* res i)))))

(define (comb k n)
  (/ (fact n)
     (* (fact k) (fact (- n k)))))

(define (term k n)
  (* (comb (- n k) 365)
     (comb k (- n k))
     (expt 2 (- k))))

(define (prob n)
  (let ((max (/ n 2)))
    (define (sum res k)
      (if (> k max)
          res
          (sum (+ res (term k n))
               (+ k 1))))
    (/ (* 1.0 (fact n) (sum 0 0))
       (expt 365 n))))

(define (find-min)
  (let loop ((n 1))
    (if (< (prob n) 1/2)
        n
        (loop (+ n 1)))))