# Review A (reconstruction fidelity): `aa_0099a8e0` gfxVertexBufferImpl_Allocate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099a8e0` |
| **VA** | `0x0099a8e0` |
| **Body** | `0x0099a8e0`–`0x0099a9a4` (196 bytes) |
| **Canonical name** | `gfxVertexBufferImpl_Allocate` |
| **Prior scaffold** | `FUN_0099a8e0` |
| **Review date** | `2026-07-29` (W22-L dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0099a8e0_gfxVertexBufferImpl_Allocate.md` |
| **System** | graphics / gfxVertexBufferImpl |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

**Allocate** GPU/system vertex-buffer resources for a constructed **gfxVertexBufferImpl**: free prior state, stash count/callback/format fields, call device allocate, plate-log on failure, optional success callback, update global VB budget stats. Returns status in **EAX** (`ret 0x10`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x0099a8e0` |
| Bytes | `read_memory` 200 B — body through dual `c2 10 00` |
| Bounds | `get_function_by_address` `0099a8e0`–`0099a9a4` |
| Callees | `get_function_callees` → prep / init / device / cleanup / log |
| Callers | `get_function_callers` → `00414c20`, `0099aa20` only |
| Strings | `read_memory` @ `0x00aa1858`, `0x00aa189c` |
| Parent | sealed `aa_00414c20` GfxVBHolder_ReplaceAndAllocate |
| Raw / clean | `aa_0099a8e0_*`, `gfxVertexBufferImpl_Allocate.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **196 bytes** / `ret 0x10` | **Confirmed** | bounds + hex epilogues |
| thiscall + 4 stack args | **Confirmed** | `c2 10 00`; stack loads after 4 pushes |
| Plate path + fail string | **Confirmed** | imm pushes + string bytes |
| Fail → clear fields + log + **−1** | **Confirmed** | decompile ≡ bytes |
| Success stats on `DAT_00d1f614` | **Confirmed** | imms `0x388`/`0x338`/`0x334` |
| Callers only holder replace + unserialize | **Confirmed** | Ghidra callers |
| Formal English arg names | **Inferred** | from stores + parent |
| Device allocate internals | out of scope | `FUN_00986a60` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Prep free `FUN_0099a820` | Yes |
| Store `+0x18` / `+0x1c` | Yes |
| Format copy `+0x34`/`+0x38` | Yes |
| Device call + fail/success split | Yes |
| Callback vtbl[0] | Yes |
| Stats bump | Yes |
| `ret 0x10` | Yes (bytes; clean documents) |

---

## 5. Gaps / open

1. Product English for four stack formals (exact FVF/decl type).
2. Identity of `DAT_00d1f634` / `DAT_00d1f614` (device + stats).
3. Full callback contract (return overwrites status).
4. Runtime / differential — open.

**Verdict:** **accept**
