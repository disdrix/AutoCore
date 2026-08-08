# R10 residual dual wave merge report

**Date:** 2026-08-05  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md`  
**Dual start:** 2570  
**Dual end:** **2606** (+36)  
**Sealed:** **36 / 36**

## Scope
Undualed inventory non-trivial callees of dualed HP managers (missions/inventory/skills/interaction/input system maps).

## Highlights
- CRT leaves: operator_new/delete/delete[]/__RTDynamicCast
- STL: tree node ctor/upper_bound/rotates; list Incsize/insert/copy/push; vector fill/trampolines
- Game: UseItem objective action; craft material list refresh; enter-world setup; tinker chance; reverse-engineer capacity; mission dialog tokens; inventory grid re-empty; display name setter

## Honesty
- Terminal accounting still true (list_functions 25671, none/raw/partial=0)
- Dual depth incomplete (2606 ≪ 25671)
- Tests: test_inventory_terminal_accounting.py 3 passed
