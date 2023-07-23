/**
 * @param {Function} fn
 */
function memoize(fn) {
    const cachedCalls = new Map();
    return function(...args) {
        const mapKey = args.join(',');
        let ans;
        if ((ans = cachedCalls.get(mapKey)) !== undefined) {
            return ans;
        }
        ans = fn(...args);
        cachedCalls.set(mapKey, ans);
        return ans;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */