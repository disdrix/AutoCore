# Wave 5 — thunk_* trivial-batch (body-proven)

| Field | Value |
|-------|-------|
| Wave | wave5 thunk trivial-batch |
| Date | 2026-07-29 |
| OWN ONLY | body-proven `thunk_*` / adjustor JMP stubs |
| Scope | NO `WORK_QUEUE` / `RESUME`; pure thin thunks only |
| Method | Ghidra `search_functions_enhanced` (`name_pattern=thunk_`, `is_thunk=true`) + `read_memory` body proof |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |

## Policy

Account pure JMP / short adjustor thunks as `trivial-batch` when the **function body** is proven to be only a transfer (typically 5-byte `E9 rel32`), not game logic. Ghidra decompiler may inline the target and show non-trivial pseudocode; **bytes win**.

| Include | Exclude |
|---------|---------|
| `thunk_FUN_*` with body = single JMP | Named game logic (even if short) |
| Adjustor: few bytes + JMP (if found) | Multi-instruction non-transfer bodies |
| Ghidra `isThunk=true` + body length ≤ few bytes | Import/CRT stubs (already on imports ledger) |

## Inventory search

| Query | Result |
|-------|-------:|
| Ghidra enhanced search `thunk_` + `is_thunk=true` | **56** |
| Name pattern `aa_.*thunk` | **0** |
| Name starts with `thunk_` (same set) | **56** |

All 56 names match `thunk_FUN_<targetVA>` and Ghidra marks `isThunk: true`.

## Body proof summary

| Metric | Value |
|--------|------:|
| Candidates examined | 56 |
| Pure JMP (`E9` + 4-byte rel32) accepted | **56** |
| Adjustor (this/ecx delta + JMP) | 0 |
| Rejected (non-pure body) | 0 |

- **Opcode class:** every entry starts with `e9` (near JMP).
- **Body size:** 5 bytes (Ghidra body range `entry` … `entry+4`), padding `cc` after.
- **Sample:** `thunk_FUN_0040f980` @ `0x0040f970` → bytes `e90b000000` (JMP to `0x0040f980`); function body `0040f970-0040f974`.
- **Decompile caveat:** `batch_decompile` follows the thunk and shows the **target** routine; do not use decompile alone to reject pure JMP stubs.

## Ledger

| File | Rows |
|------|-----:|
| [`docs/reconstruction/coverage/trivial_batch_thunks.jsonl`](../coverage/trivial_batch_thunks.jsonl) | **56** |

Row shape:

```json
{"addr": "0x0040f970", "name": "thunk_FUN_0040f980", "reason": "pure JMP thunk (E9 rel32); Ghidra isThunk; body 5 bytes", "bytes": "e90b000000"}
```

### Full accepted set (addr → name → bytes)

| Addr | Name | Bytes |
|------|------|-------|
| `0x0040f970` | `thunk_FUN_0040f980` | `e90b000000` |
| `0x0040fd50` | `thunk_FUN_0040d9c0` | `e96bdcffff` |
| `0x00424760` | `thunk_FUN_00424770` | `e90b000000` |
| `0x00427040` | `thunk_FUN_004271c0` | `e97b010000` |
| `0x00428c20` | `thunk_FUN_00460a20` | `e9fb7d0300` |
| `0x00431ad0` | `thunk_FUN_00431ae0` | `e90b000000` |
| `0x00437ac0` | `thunk_FUN_00437f20` | `e95b040000` |
| `0x00437d70` | `thunk_FUN_004383f0` | `e97b060000` |
| `0x0043b990` | `thunk_FUN_00745ff0` | `e95ba63000` |
| `0x0043d640` | `thunk_FUN_005b2ba0` | `e95b551700` |
| `0x004434c0` | `thunk_FUN_0096efd0` | `e90bbb5200` |
| `0x004455f0` | `thunk_FUN_00445a90` | `e99b040000` |
| `0x00445740` | `thunk_FUN_00445dc0` | `e97b060000` |
| `0x00449430` | `thunk_FUN_00449630` | `e9fb010000` |
| `0x0044ac30` | `thunk_FUN_0044aeb0` | `e97b020000` |
| `0x004512b0` | `thunk_FUN_004380f0` | `e93b6efeff` |
| `0x00456e80` | `thunk_FUN_00457000` | `e97b010000` |
| `0x00457ab0` | `thunk_FUN_00748600` | `e94b0b2f00` |
| `0x0045fa10` | `thunk_FUN_0045faf0` | `e9db000000` |
| `0x00460d90` | `thunk_FUN_00461190` | `e9fb030000` |
| `0x00460f80` | `thunk_FUN_00461350` | `e9cb030000` |
| `0x004627b0` | `thunk_FUN_004627e0` | `e92b000000` |
| `0x00465c30` | `thunk_FUN_00465d70` | `e93b010000` |
| `0x0051b890` | `thunk_FUN_00512060` | `e9cb67ffff` |
| `0x00548f90` | `thunk_FUN_00578a60` | `e9cbfa0200` |
| `0x0055cf50` | `thunk_FUN_0055cdf0` | `e99bfeffff` |
| `0x0055d8b0` | `thunk_FUN_0055d750` | `e99bfeffff` |
| `0x0059cbc0` | `thunk_FUN_0059c8a0` | `e9dbfcffff` |
| `0x005a5b60` | `thunk_FUN_005ee650` | `e9eb8a0400` |
| `0x005d4a50` | `thunk_FUN_00584290` | `e93bf8faff` |
| `0x005d8350` | `thunk_FUN_005d2470` | `e91ba1ffff` |
| `0x005d83e0` | `thunk_FUN_00508390` | `e9abfff2ff` |
| `0x005e6b50` | `thunk_FUN_005a61d0` | `e97bf6fbff` |
| `0x005e6b60` | `thunk_FUN_005a6840` | `e9dbfcfbff` |
| `0x005f5150` | `thunk_FUN_00646310` | `e9bb110500` |
| `0x005fa5d0` | `thunk_FUN_005b2590` | `e9bb7ffbff` |
| `0x005fb690` | `thunk_FUN_005fa9b0` | `e91bf3ffff` |
| `0x006006c0` | `thunk_FUN_00636290` | `e9cb5b0300` |
| `0x0060cec0` | `thunk_FUN_00637dc0` | `e9fbae0200` |
| `0x006368e0` | `thunk_FUN_00651a80` | `e99bb10100` |
| `0x0064aed0` | `thunk_FUN_0064ae60` | `e98bffffff` |
| `0x0064fdd0` | `thunk_FUN_0065ea90` | `e9bbec0000` |
| `0x0064fde0` | `thunk_FUN_0065e6c0` | `e9cbec0000` |
| `0x0064fec0` | `thunk_FUN_005fb100` | `e93bb2faff` |
| `0x0064fed0` | `thunk_FUN_005fa9b0` | `e9bbb7faff` |
| `0x0065e060` | `thunk_FUN_0065d930` | `e9cbf8ffff` |
| `0x0065e2c0` | `thunk_FUN_0065e1e0` | `e91bffffff` |
| `0x0065e450` | `thunk_FUN_0065e3b0` | `e95bffffff` |
| `0x0065eab0` | `thunk_FUN_0065e6c0` | `e90bfcffff` |
| `0x00687650` | `thunk_FUN_00685ba0` | `e94be5ffff` |
| `0x006933b0` | `thunk_FUN_006919f0` | `e93be6ffff` |
| `0x00695790` | `thunk_FUN_006954f0` | `e95bfdffff` |
| `0x006a0e90` | `thunk_FUN_006916d0` | `e93b08ffff` |
| `0x006a2470` | `thunk_FUN_0069a010` | `e99b7bffff` |
| `0x006c7e80` | `thunk_FUN_006cec70` | `e9eb6d0000` |
| `0x0076c5c0` | `thunk_FUN_0076c4d0` | `e90bffffff` |

## Stamp integration

Updated [`stamp_inventory_status.py`](../coverage/stamp_inventory_status.py) so `load_trivial_addrs()` also reads `trivial_batch_thunks.jsonl` (alongside unwind + imports).

Notes:

- Stamp only sets inventory `status=trivial-batch` when the VA is in a trivial ledger **and** not already covered by a function-record / raw unit (`have`). Many of these thunks already show `full` in inventory from prior unit emission; the **durable account for pure JMP is still this ledger**.
- Parent does **not** need a further stamp extension for this file unless additional thunk ledgers appear under new names.

## Count

| Metric | Count |
|--------|------:|
| **Body-proven pure thunks written** | **56** |
| Rejected | 0 |
| aa_*thunk* | 0 |

## Out of scope (this agent)

- `WORK_QUEUE` / `RESUME` edits
- Restamping inventory status as a global run (stamp script ready; optional parent run)
- Non-`thunk_*` short stubs (CRT/imports use separate ledger)
- Dual-review of JMP **targets**
