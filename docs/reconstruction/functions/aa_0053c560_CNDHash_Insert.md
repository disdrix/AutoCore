# Function record: CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c560` |
| **Canonical name** | `CNDHash_Insert` |
| **Address** | `0x0053c560` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container (callers: continent unlock / create-packet slots) |
| **Completion status** | **accept-with-gaps** — dual A/B 2026-07-29; freelist this-link open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Generic CNDHash insert(key, value). Null value → `E_POINTER` (`0x80004003`). Soft flag (`allowDuplicate`) + existing key → return **1** without insert. Hard duplicate → log + `E_FAIL` (`0x80004005`). Else allocate 0x1c node (vtbl `PTR_FUN_009cefd4`), head-insert into bucket (`key & mask`), append global list, `count++`, return **0**. Traversal lock at `this+0x1d` logs only (does not abort).

Used by `CVOGReaction_UnlockContinentObject` (`char+0x534`) and `CVOGCharacter_ApplyCreateFromPacket` continent slots. Twin inserts at `0x0053c360` / `0x0053c660` (same CF, different node vtbl) are separate units.

## Signature (decompiler-derived)

```c
int __thiscall CNDHash_Insert(void *this, uint key, void *value, char allowDuplicate);
// allowDuplicate semantic: soft-skip-if-exists (return 1), not multi-value insert
```

## Return codes

| Value | Meaning |
|---|---|
| `0` | inserted |
| `1` | soft: key already present (`allowDuplicate != 0`) |
| `0x80004003` | null value (`E_POINTER`; signed `-0x7fffbffd` in decompile) |
| `0x80004005` | hard duplicate (`E_FAIL`; signed `-0x7fffbffb`) |

## Layout (partial)

**Hash:** `+0x08` mask, `+0x0c` count, `+0x10` buckets*, `+0x14` listHead, `+0x18` listTail, `+0x1d` lockedForTraversal.

**Node (0x1c):** `+0` vtbl `009cefd4`, `+4` touch, `+8` value*, `+0xc` bucketNext, `+0x10` key, `+0x14` listNext, `+0x18` listPrev.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053c560_CNDHash_Insert.md`
- Annotated: `docs/reconstruction/raw/aa_0053c560_CNDHash_Insert.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_Insert.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0053c560_CNDHash_Insert.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0053c560_CNDHash_Insert.md`
- Residual: `docs/reconstruction/reviews/a_0053c560.md`

## Callers / callees

| Direction | Symbol | Address / notes |
|---|---|---|
| Caller | `CVOGReaction_UnlockContinentObject` | `0x00531c80` — hash `char+0x534`, allowDup=0 |
| Caller | `CVOGCharacter_ApplyCreateFromPacket` | `0x00534bd0` — continent slots, allowDup=0 |
| Callee | `CNDHash_LookupByKey` | existence check |
| Callee | `FUN_0053ada0` | freelist node alloc (0x1c; ECX freelist Open) |
| Callee | `FUN_00537d30` | bucket chain integrity |
| Callee | `FUN_007a4480` | debug log |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **Confirmed** (live ≡ force ≡ raw) |
| HRESULT return codes | **Confirmed** |
| Hash / node offsets used by body | **High** |
| Soft-flag semantics (not multi-insert) | **High** |
| Freelist this-offset / full header | **Open** |
| Parameter names (Ghidra) | **High** (names); soft-flag product English **Probable** |
