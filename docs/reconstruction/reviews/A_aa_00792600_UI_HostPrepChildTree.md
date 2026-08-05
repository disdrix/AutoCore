# Review A (reconstruction fidelity): `aa_00792600` UI_HostPrepChildTree

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792600` |
| **VA** | `0x00792600` |
| **Canonical name** | `UI_HostPrepChildTree` (inferred; Ghidra `FUN_00792600`) |
| **Plate alias** | `Named_VOG_DEBUG_STOP_00792600` (debug string) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00792600_UI_HostPrepChildTree.md` |
| **System** | client UI host / CreateChildWidgets prolog |
| **Evidence pass** | Live decompile + callees; high fan-in CreateChildWidgets callers (Trade/CharSheet/Arena/NpcMission/…) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Pre-rebuild prep** for a 2D UI dialog host (`this`), invoked first by nearly every `CreateChildWidgets` body:

1. Vfunc `vtbl+0x3d8()` — if true → debug stop `"VOG_DEBUG_STOP"`.
2. If host resolution fields `this[0x70]/[0x71]` ≠ globals `DAT_00d1e818`/`DAT_00d1e81c` → vfunc `vtbl+0x28(0)` (resolution change path).
3. Set flag `this+0x8c` (`param_1[0x23]` as byte), clear `this[0x128]`/`this[0x129]`.
4. `operator_new(0x34)` + `FUN_004280f0` → store at `this[0x130]` (fresh helper object).
5. Child-hash / direction widget branch on `this+0xbf`:
   - **Clear path:** copy linked child from `this[0xa9]+4` into `this[0xaa]`.
   - **Rebuild path:** new(0x80)+`FUN_007560d0` → `this[0xaa]`; `FUN_00756320(1)`; link into `this[0xa9]+4`; optional **Directional** widget (`FUN_0096d830` / `FUN_0096e430("Directional")` / direction material hooks) when `this[0x30]` byte clear.
6. Flag `this+0x492 = 1`; vfunc `vtbl+0x330(7)`.
7. **Hash traverse lock** on `this[0x136]`:
   - Guard strings `HashError:TraversalLock…` / `HashError:TraverseToNext…`.
   - Walk nodes via `+0x14` links; for each child object at node`+8` call `vtbl+0xa8(child)` (detach/destroy prep), bump counters `this[0x1a]` / max `this[0x1c]`, vfunc `vtbl+0x3f4(1)`.
8. Unlock traversal flag.

Effect: clear/reparent host child bookkeeping and **tear down existing hashed children** so CreateChildWidgets can allocate a fresh tree.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00792600_FUN_00792600.md` |
| Annotated | `docs/reconstruction/raw/aa_00792600_FUN_00792600.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00792600.cpp` |
| Function record | `docs/reconstruction/functions/aa_00792600_FUN_00792600.md` |
| Caller duals | Trade/CharSheet/Arena/NpcMission CreateChildWidgets |
| Live | decompile ≡ raw; strings sealed |

**Three-rep:** present.

---

## 3. Signature

```c
// __fastcall / thiscall-style: ECX = UI host*
void UI_HostPrepChildTree(void *host);
```

Decompiler marks `__fastcall int *param_1` — host pointer in ECX. No stack formals.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Debug vfunc + optional VOG_DEBUG_STOP | **Yes** | **High** |
| Resolution mismatch → vfunc+0x28(0) | **Yes** | **High** |
| Flags + new(0x34) helper @ `[0x130]` | **Yes** | **High** |
| Dual path on byte `+0xbf` | **Yes** | **High** |
| Optional Directional widget | **Yes** | **High** (string) |
| Hash lock + child walk + vtbl+0xa8 | **Yes** | **High** |
| Unlock + SEH restore | **Yes** | **High CF** |
| No XML load in this unit | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = CreateChildWidgets host prep / child clear | **High** | universal first call pattern |
| Hash traversal destroys/detaches children | **High CF** | vtbl+0xa8 per node |
| Directional branch string-backed | **High** | `"Directional"` / `"Direction"` |
| Exact host C++ base class | **Tentative** | large UI object |
| Meaning of every flag offset | **Tentative** | residual |
| Bit-exact / runtime | **Open** | deferred |
| xref_count ~137 | **High** | inventory |

---

## 6. Gaps

1. Product class name for host and hash table at `[0x136]`.
2. Precise destroy vs reparent semantics of `vtbl+0xa8` / `+0x3f4`.
3. When `+0xbf` is set (rebuild Directional) vs clear path.
4. Full layout of resolution globals `DAT_00d1e818/81c`.

**Verdict:** **accept-with-gaps**
