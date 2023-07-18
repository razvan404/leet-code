Array.prototype.last = function() {
    return this.length ? this.at(this.length - 1) : -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
