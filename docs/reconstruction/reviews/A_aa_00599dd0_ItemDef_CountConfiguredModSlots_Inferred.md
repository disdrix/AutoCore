# Review A (reconstruction fidelity): `aa_00599dd0` ItemDef_CountConfiguredModSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00599dd0` |
| **VA** | `0x00599dd0` |
| **Body** | `0x00599dd0`–`0x00599e0d` (`ret` / `int3`) |
| **Canonical name** | `ItemDef_CountConfiguredModSlots_Inferred` |
| **Ghidra name** | `FUN_00599dd0` |
| **Prior names** | `FUN_00599dd0`; scaffold `Named_CalleeOf_Named_Required_Combat_00599dd0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00599dd0_ItemDef_CountConfiguredModSlots_Inferred.md` |
| **System** | inventory-transfer / item def layout / loot broken-roll gate |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, `get_function_callers` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Leaf counter:** how many of five consecutive **signed dword slots** on an item-def (or def-like) object are configured (not the sentinel `-1`).

```c
// thiscall / fastcall: ECX = object*
// returns char/AL count in 0..5
char ItemDef_CountConfiguredModSlots_Inferred(void *obj) {
  char n = (*(int *)((char *)obj + 0x498) != -1);
  if (*(int *)((char *)obj + 0x49c) != -1) n++;
  if (*(int *)((char *)obj + 0x4a0) != -1) n++;
  if (*(int *)((char *)obj + 0x4a4) != -1) n++;
  if (*(int *)((char *)obj + 0x4a8) != -1) n++;
  return n;
}
```

Primary product use already dual-sealed at caller `Item_HasModSlotConfig_Inferred` (`0x00513cf0`): **`n > 0` ⇒ def exposes at least one option/mod slot** (gate on ~11% broken roll). Many additional callers (tooltips, garage UI, character panels) reuse the same count.

**Not** a bool predicate (returns 0..5), not a scanner over a variable-length list, not an allocator.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00599dd0_FUN_00599dd0.md` |
| Raw / annotated | `docs/reconstruction/raw/aa_00599dd0_FUN_00599dd0*.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00599dd0.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x00599dd0` (2026-07-29) — **≡ clean CF** |
| Body bytes | `read_memory 0x00599dd0` length 64: `OR EDX,-1` / `XOR EAX,EAX` / five `CMP [ECX+off],EDX` / `ret` |
| Caller dual | `A\|B_aa_00513cf0_Item_HasModSlotConfig_Inferred` |
| Callers (live) | `00513cf0`, `00522060`, `00524190`, `0052d450`, `0052e1d0`, `0052e640`, `005316c0`, UI tooltip `00847ad0`, garage/UI `0089a260`/`0089b090`, others |

---

## 3. ABI / layout

| Item | Evidence |
|---|---|
| Register object in **ECX** | Body: `CMP [ECX+0x498], EDX` (`39 91 98 04 00 00`) |
| Stack cleanup | Plain `C3` `ret` — no stack formals |
| First field init | `XOR EAX,EAX`; if first `!= -1` → `MOV EAX,1` (bool→0/1 then add) |
| Subsequent fields | `ADD EAX,1` when `!= -1` |
| Offsets | `+0x498, +0x49c, +0x4a0, +0x4a4, +0x4a8` (five dwords, stride 4) |
| Sentinel | `-1` (`EDX = 0xFFFFFFFF`) |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Counts five fixed dwords `!= -1` | **Confirmed** | live body + bytes |
| Returns 0..5 in AL | **Confirmed** | |
| ECX = object (thiscall/fastcall) | **Confirmed** | |
| Clean ≡ raw ≡ live CF | **Confirmed** | scaffold identity |
| Used as mod-slot presence gate (`n>0`) | **High** | `00513cf0` dual |
| Fields are specifically “mod” IDs | **Probable** | product lexicon residual; could be option/skill/dye IDs |
| Exact object class (item def vs nested blob) | **Probable** | callers pass different hosts; offsets sealed on *that* object |
| Product English name | **Tentative** | `_Inferred` |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Five fixed offsets | **Yes** |
| Sentinel `-1` | **Yes** |
| Additive count | **Yes** |
| No callees / no RNG | **Yes** |

---

## 6. Gaps / open

1. Product name for the five fields (mod vs option vs skill CBID).
2. Whether every caller’s ECX is the same def type (shared layout vs aliases).
3. Runtime not required for this pure leaf.

**Verdict:** **accept-with-gaps** — CF and layout **Confirmed**; field English residual only.
