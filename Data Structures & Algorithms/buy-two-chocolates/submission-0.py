class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        p1 = float("inf")
        p2 = float("inf")
        for price in prices:
            if price < p1:
                p2 = p1
                p1 = price

            elif price < p2:
                p2 = price
        return money if money-p1-p2<0 else money-p1-p2