# Review A (reconstruction fidelity): `aa_004294f0` List_TraversalLock

| Field | Value |
|---|---|
| **Stable ID** | `aa_004294f0` |
| **VA** | `0x004294f0` |
| **Canonical name** | `List_TraversalLock` (registry; string-sealed role) |
| **Ghidra symbol** | `FUN_004294f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_004294f0_List_TraversalLock.md` |
| **System** | `inventory-transfer` / shared `client::list` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Acquire traversal ownership** on a critical-section list manager:

1. If `*(list+0x28) != 0` (already locked for traversal):
   - Log `"VOG_DEBUG_STOP"`.
   - Capture optional call stack into a ~4 KiB wchar buffer via `FUN_0076dae0` / `FUN_0076d9d0` / `FUN_0076d8b0` when `DAT_00d0dfb0 != 0`.
   - Log `"List Error!  TraversalLock Call Stack:\n%s\n"`.
   - **Return without** re-entering the CS or changing the flag.
2. Else:
   - `EnterCriticalSection(list+4)`.
   - Set `*(list+0x28) = 1`.
   - Return (**CS remains held** for the iteration window).

Companion unlock is **caller-owned**: clear `+0x28` then `LeaveCriticalSection(list+4)` (see Contains / grid walks / RebuildItemWidgets).

No membership mutation. No node walk.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004294f0_FUN_004294f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004294f0_FUN_004294f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004294f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004294f0_FUN_004294f0.md` |
| Live decompile | Ghidra `decompile_function` / `force_decompile` @ `0x004294f0` — **A ≡ B ≡ raw** |
| Live bytes | `read_memory` @ `0x004294f0` length 160 |
| Registry | `NAMING_REGISTRY.md` → `List_TraversalLock` |
| Sibling usage | `A_aa_00415c00`, `A_aa_00571010`, `A_aa_00860700` |
| Xrefs | Ghidra bulk xrefs — **many** inventory / UI / mission list walkers |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall`/`thiscall` list in `ECX`; plain `ret` | **High** | `mov esi,ecx`; epilogue `c3` |
| Flag `list+0x28` already set → debug path, no second Enter | **High** | String + CF sealed |
| Success path: EnterCS(`+4`) then `*(+0x28)=1` | **High** | Decompile ≡ bytes (`c6 46 28 01`) |
| Product role "TraversalLock" | **High** | Literal `"List Error!  TraversalLock Call Stack"` |
| Nested lock is soft (log + return) not throw | **High** | Contrast clear/insert throw `0x80070005` |
| Call-stack dump requires `DAT_00d0dfb0` | **High** | Gate around `0076d9d0`/`0076d8b0` |
| Exact list class product name | **Probable** | Shared family; no RTTI on this VA |
| All callers always unlock | **Caller-owned** | Not this body's job |

---

## 4. Control flow: clean ≡ raw ≡ force

| Stage | Match |
|---|---|
| `if (byte[this+0x28] != 0)` → debug + return | **Yes** |
| Else EnterCS(`this+4`); flag=1 | **Yes** |
| No iterate / no free / no insert | **Yes** |
| Dual A≡B force | **Yes** |

### Instruction seal (entry / success tail)

```text
55 8B EC 83 E4 F8 B8 50 10 00 00 E8 …   ; frame + chkstk (~0x1050)
56 8B F1 80 7E 28 00 57 74 76           ; this; if +0x28==0 → lock path
… debug stack dump + log …
8D 4E 04 51 FF 15 …                    ; EnterCriticalSection(this+4)
5F C6 46 28 01 5E … C3                 ; flag=1; ret
```

---

## 5. Layout (list manager)

| Offset | Role |
|---|---|
| `+0x04` | `CRITICAL_SECTION` |
| `+0x28` | TraversalLock flag (byte) |

Shared with `List_IterateNext` / `List_IterateNext_u64` / clear / insert family.

---

## 6. Callers (role)

Hundreds of xrefs: inventory grid Find/Count/Contains/Remove, UI sheet rebuild, mission/list helpers, trade/cargo. **Universal list traversal gate**, not inventory-exclusive.

---

## 7. Gaps

1. Product C++ class name for the list object (beyond `client::list` family).
2. Whether same-thread re-lock is intentional API (yes in practice — Contains after outer lock).
3. Runtime verification of stack dump path when `DAT_00d0dfb0` set.

**Verdict:** **accept-with-gaps** — CF + string role **sealed**.
