for (let i = 0; i < n; i += step) {
    const t = arr.slice(i).concat(arr.slice(0, i));
    }
    if (ans === null || compareArray(t, ans) < 0) {
        ans = t;
    }
}

return ans.join('');