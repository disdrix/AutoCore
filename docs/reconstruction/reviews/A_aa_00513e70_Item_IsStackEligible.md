# Review A (reconstruction fidelity): `aa_00513e70` Item_IsStackEligible

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513e70` |
| **VA** | `0x00513e70` |
| **Canonical name** | `Item_IsStackEligible` (proposed; was `FUN_00513e70`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + bytes) |
| **Counterpart** | `reviews/B_aa_00513e70_Item_IsStackEligible.md` |
| **Residual scratch** | `reviews/a_00513e70.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Per-item stack-merge / stack-display eligibility probe.** Returns whether the item **may** participate in stack-oriented behavior (merge scan, loot `xN`, peer find). Does **not** compute remaining stack capacity and does **not** mutate state.

**Calling convention:** single object pointer in `ECX` (Ghidra `__fastcall`; MSVC item/`this` in ECX). Zero stack args. Plain `ret`. Returns `1` / `0` in `EAX`.

| Slot | Role | Evidence |
|------|------|----------|
| `this` / `param_1` (ECX) | `Item*` / cloned object | `mov eax,[ecx+0xa8]`; call sites pass inventory item |

**Side effects:** none (read-only; no callees).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00513e70_FUN_00513e70.md` |
| Annotated | `docs/reconstruction/raw/aa_00513e70_FUN_00513e70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00513e70.cpp` → `Item_IsStackEligible` notes |
| Function record | `docs/reconstruction/functions/aa_00513e70_FUN_00513e70.md` |
| Live re-decompile | Ghidra @ `0x00513e70` — **≡ raw body** |
| Bytes | Ghidra `read_memory` 64 B @ `0x00513e70` — ends `b8 01 00 00 00 c3` + `CC` |
| Capacity peer | `0x0040abf0` decompile (qty + delta ≤ max) |
| Broken setter | `0x00513de0` decompile (mask `0x80000`) |
| Cross duals | FindFreeForItem stack gate; CountItemsByCbid Broken seal; RecvInventoryAddItem loot gate |

**Not performed:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff.

---

## 3. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| Load holder `@item+0xa8`, blob `@holder+0x3c` | **Yes** |
| Test blob `+0x3f2` mask `0x40` | **Yes** |
| If flag set: test Broken bit 19 @ `item+0x17c` | **Yes** |
| Broken clear + flag set → return 1 | **Yes** |
| Else type `holder+0x38 == 4` → return 1 | **Yes** |
| Else return 0 | **Yes** |
| No external calls | **Yes** |

### Closed form (sealed)

```text
return typeClass==4 || (stackFlag_0x40 && !ItemFlag_Broken);
```

Decompiler `if (((!flag || broken) && type!=4) return 0; return 1;` is **logically equivalent**.

---

## 4. Not capacity / not broken-only

| Related unit | VA | Role vs this function |
|---|---|---|
| Stack **capacity** | `0x0040abf0` | After eligibility, callers ask “does peer have room for qty?” |
| Broken **setter** | `0x00513de0` | Writes bit 19; not called here |
| Broken **read** | inline in body | Same bit as loot `"Broken: "` / overlay |

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Function boundary / size (`00513e70`–`00513ea3`) | **High / Sealed** |
| ECX = item, 0 stack args | **High / Sealed** |
| Boolean formula | **High / Sealed** |
| Role = eligibility (not capacity) | **High / Sealed** |
| Broken blocks (does not enable) non-type-4 path | **High / Sealed** |
| Type-4 product name | Tentative / Open |
| Original PDB name | Open |
| Overall | **Probable / accept-with-gaps** |

---

## 6. Verdict

### **accept-with-gaps**

**Accept:** Live body matches raw; bytes seal formula without decompiler ambiguity; capacity and broken-setter ownership split cleanly; dual residual documents mislabels from prior wave notes.

**Gaps:** type-4 taxonomy, original symbol, runtime/diff.
