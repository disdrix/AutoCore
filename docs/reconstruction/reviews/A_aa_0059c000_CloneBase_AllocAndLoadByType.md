# Review A (reconstruction fidelity): `aa_0059c000` CloneBase_AllocAndLoadByType

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059c000` |
| **VA** | `0x0059c000`–`0x0059c443` |
| **Canonical name** | `CloneBase_AllocAndLoadByType` |
| **Prior / alias** | `FUN_0059c000`; parent-seed `Named_CalleeOf_Named_VOG_DEBUG_STOP_0059c000` (**misleading**) |
| **Review date** | `2026-07-29` (W19-F OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0059c000_CloneBase_AllocAndLoadByType.md` |
| **System** | gamedata / clonebase materialize |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs/analyze (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate + DB-load a **typed clonebase object** for a catalog **record**, store it at `record+0x3c`, then fill name slots. Optional cache path when `DAT_00b04694` is set. Unknown type returns **`E_FAIL`**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0059c000_FUN_0059c000.md` (+ W19-F append) |
| Annotated | `docs/reconstruction/raw/aa_0059c000_FUN_0059c000.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CloneBase_AllocAndLoadByType.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0059c000.cpp` |
| Function record | `docs/reconstruction/functions/aa_0059c000_CloneBase_AllocAndLoadByType.md` |
| Live decompile | ≡ raw type switch + success tail |
| Live bytes | SEH prolog; stack arg; switch tables; `mov eax,0x80004005`; bare `ret` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence | Conf |
|---|---|---|
| Stack arg record (not ECX thiscall) | `mov esi,[esp+…]` after SEH/`sub esp` | **High** |
| cdecl bare `ret` | epilogue `c3` (not `c2 xx 00`) | **High** |
| Body range | `0059c000`–`0059c443` | **High** |
| Return int status | 0 / loader HRESULT / `0x80004005` | **High** |

### 3.2 Record map — **SEALED**

| Off | Role | Conf |
|---:|---|---|
| `+0x34` | cbid / id → cache + `obj+4` | **High** |
| `+0x38` | type switch key | **High** |
| `+0x3c` | allocated object* | **High** |
| `+0x40` | name copy sink | **High** |
| `+0x188` | secondary name `strncpy` 0x41 | **High** |

### 3.3 Control flow — **SEALED**

1. Optional cache: `DAT_00b04694` → `FUN_00540850(+0x34)` → skip switch if non-null.
2. Type switch (tables `0x0059c474` / `0x0059c444`) with sealed case set and per-type alloc sizes.
3. Non-zero loader status early-return.
4. Success name fill via `PTR_FUN_00af8c9c` + `FUN_00403450` + copies; return 0.
5. Default: `E_FAIL` (`-0x7fffbffb` ≡ `0x80004005` bytes).

### 3.4 Named type arms — **SEALED**

| Type | Loader (product name where present) |
|---:|---|
| `0xe` | `VehicleDb_LoadCloneBase` (alloc `0x744`) |
| `10` | `DB_ReadPowerPlantSpecific` (alloc `0x4cc`) |
| shared generic set | `FUN_007e59d0` + vtbl `0x009d55fc` (alloc `0x4c0`) |
| `0x14` | whole-arm `FUN_0059b620(rec)` |

### 3.5 Three-rep fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline |
| Live re-decompile 2026-07-29 | **≡** raw |
| Bytes (prolog / E_FAIL / ret) | **sealed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Materialize typed clonebase by type | **High** | switch + loaders |
| cdecl ABI | **High** | bytes |
| E_FAIL default | **High** | `B8 05 40 00 80` |
| Parent-seed VOG_DEBUG_STOP sole purpose | **Falsified** | failure log only in parent |
| Product/PDB name | **Open** | structural name only |
| All type English labels | **Open** | vehicle/powerplant partial |
| Cache flag semantics | **Open** | `DAT_00b04694` |
| Runtime / bit-exact / diff | **Open** | not run |

---

## 5. Gaps / open

1. Original compiler/PDB symbol.
2. Product names for every type code and remaining loaders/ctors.
3. Whether double `FUN_00403450` on success is intentional dual-fill (bytes/port note).
4. Runtime / differential verification.

**Verdict:** **accept-with-gaps**
