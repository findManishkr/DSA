/*

 Problem: https://leetcode.com/problems/container-with-most-water/
 Concept : Two Pointer

*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;

        int i = 0, j = n - 1;

        while (i < j) {
            int H = min(height[i], height[j]);
            int W = (j - i);

            maxArea = max(maxArea, W * H);

            // move pointers
            if (height[i] < height[j])
                i++;
            else if (height[j] < height[i])
                j--;
            else
                i++, j--;
        }

        return maxArea;
    }
};


int main(int argc, char const *argv[]) {


    

    return 0;
}




/*
═══════════════════════════════════════════════════════════════════════════════
                         🧬 Intuition
═══════════════════════════════════════════════════════════════════════════════
We need to find two lines that, together with the x-axis, can form a container 
that holds the most water.  

The **amount of water** a pair (i, j) can hold is limited by:
    → the *shorter* of the two heights (since water can’t spill over the shorter side),
    → multiplied by the *distance* between them (the width).

To maximize the area:
- A higher line can improve height.
- A wider distance increases width.
But increasing one usually decreases the other — hence the need for balance.

───────────────────────────────────────────────────────────────────────────────


═══════════════════════════════════════════════════════════════════════════════
                         🧩 Approach
═══════════════════════════════════════════════════════════════════════════════
1️⃣ Start with two pointers:
        i = 0 (left),  j = n - 1 (right)

2️⃣ Compute the area:
        area = min(h[i], h[j]) * (j - i)

3️⃣ Update maxArea if the current area is larger.

4️⃣ Move the pointer that has the smaller height:
   - Because increasing the shorter line might improve height,
     while moving the taller line only decreases width without improving height.

5️⃣ Continue until i < j.

───────────────────────────────────────────────────────────────────────────────
Time Complexity  →  O(n)  
Space Complexity →  O(1)
───────────────────────────────────────────────────────────────────────────────


═══════════════════════════════════════════════════════════════════════════════
                         💡 Code Explanation
═══════════════════════════════════════════════════════════════════════════════
• `int i = 0, j = n - 1;`  
   → Initialize two pointers at both ends.

• `int H = min(height[i], height[j]);`  
   → The limiting height of the container.

• `int W = (j - i);`  
   → The width (horizontal distance).

• `maxArea = max(maxArea, W * H);`  
   → Update the maximum found so far.

• Pointer movement:
   - If height[i] < height[j] → increment i  
   - Else if height[j] < height[i] → decrement j  
   - Else (equal) → move both

───────────────────────────────────────────────────────────────────────────────
The loop continues while i < j, guaranteeing every possible valid container 
is considered under the optimal movement rule.
───────────────────────────────────────────────────────────────────────────────


═══════════════════════════════════════════════════════════════════════════════
            🧠 Proof and Reasoning for the Two-Pointer Solution
═══════════════════════════════════════════════════════════════════════════════

Let f(i, j) return the area between two lines:
        f(i, j) = min(h[i], h[j]) * (j - i)    
where  j > i  and both i, j ∈ [0, n - 1].

We want to maximize  f(i, j).

──────────────────────────────────────────────────────────────────────────────
1️⃣ Why we move the pointer at the lower height
──────────────────────────────────────────────────────────────────────────────
Assume w.l.o.g. that  h[i] < h[j].
Then: 
        min(h[i], h[j]) = h[i]

If we try to increase h[j] by moving the right pointer,
even to a bigger value (say h[j] + x),
the minimum remains →  min(h[i], h[j] + x) = h[i]

So the height part does not change, but the width decreases:
        f(i, j − 1) < f(i, j)

Thus:
➡️ Moving the taller pointer cannot increase the area.  
➡️ Only moving the smaller height pointer can possibly help.

──────────────────────────────────────────────────────────────────────────────
2️⃣ Why moving the smaller pointer can increase area
──────────────────────────────────────────────────────────────────────────────
If h[i] is smaller, moving i → i + 1 may find a height h[i+1] > h[i].

Then:
        min(h[i+1], h[j]) ≥ min(h[i], h[j]) = h[i]

So the height may improve, while width decreases by only 1.

Therefore:
➡️ Moving the shorter line has a chance to increase the area.  
➡️ Keeping the shorter line forever will never increase area.

──────────────────────────────────────────────────────────────────────────────
3️⃣ Interesting Case: h[i] == h[j]
──────────────────────────────────────────────────────────────────────────────
Case 1 → Move i  
Width shrinks.  
Compare:
        f(i+1, j) < f(i, j)
even if h[i+1] > h[i], because:
        min(h[i+1], h[j]) = h[j]
(width loss dominates)

Case 2 → Move j  
Same logic:
        f(i, j−1) < f(i, j)
because:
        min(h[i], h[j−1]) = h[i]

Thus when heights are equal:
➡️ Either pointer can be moved, result is the same.  
➡️ i++ or j-- or even both i++, j-- does not alter correctness.

──────────────────────────────────────────────────────────────────────────────
✅ Final Conclusion
──────────────────────────────────────────────────────────────────────────────
Since:
➡️ Moving the taller line never increases area.  
➡️ Moving the shorter line may increase area.  
➡️ When equal, either move is safe.  
➡️ Width only decreases, so we must eliminate useless choices quickly.

Therefore:
✔️ Always move the pointer with the smaller height.  
✔️ This never removes a possibility for a better answer.  
✔️ This guarantees the O(N) two-pointer solution is correct.
═══════════════════════════════════════════════════════════════════════════════
*/
