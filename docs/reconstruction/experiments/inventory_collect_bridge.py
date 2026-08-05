"""
Evidence-backed model: inventory count → collect objective progress.

Sealed from:
  InventoryGrid_CountItemsByCbid @ 0x005711c0
  CVOGObjectiveRequirement_Collect_Eval @ 0x00611940
"""

from __future__ import annotations

from dataclasses import dataclass, field


@dataclass
class GridItem:
    cbid: int
    quantity: int
    # item+0x17c bit 19 (object[0x5f] >> 19 & 1) = Broken — sealed dual residual.
    # `flag_bit19` kept as the field name for test/compat; semantic name is is_broken.
    flag_bit19: bool = False

    @property
    def is_broken(self) -> bool:
        return self.flag_bit19


@dataclass
class InventoryGrid:
    items: list[GridItem] = field(default_factory=list)


def count_items_by_cbid(
    grid: InventoryGrid, item_cbid: int, include_broken: bool = False, **kwargs
) -> int:
    """aa_005711c0: sum quantities matching CBID; exclude Broken unless include_broken."""
    if "include_flagged" in kwargs:
        include_broken = bool(kwargs["include_flagged"])
    total = 0
    for it in grid.items:
        if it.cbid != item_cbid:
            continue
        broken = getattr(it, "is_broken", False) or getattr(it, "flag_bit19", False)
        if (not include_broken) and broken:
            continue
        total += it.quantity
    return total


def collect_eval_fraction(grid: InventoryGrid | None, item_cbid: int, num_to_collect: int) -> float:
    """aa_00611940: min(1, count/NumToCollect); 0 if no grid; 1 if need==0.

    Image re-calls Count when incomplete (no CSE); model uses two walks when
    frac < 1. Always exclude Broken (includeBroken=0). stack1 objState unread.
    """
    if num_to_collect == 0:
        return 1.0
    if grid is None:
        return 0.0
    count = count_items_by_cbid(grid, item_cbid, include_broken=False)
    frac = count / float(num_to_collect)
    if frac >= 1.0:
        return 1.0
    # Second walk (asm @ 0x006119a3) — equivalent if grid unchanged
    count = count_items_by_cbid(grid, item_cbid, include_broken=False)
    return count / float(num_to_collect)
