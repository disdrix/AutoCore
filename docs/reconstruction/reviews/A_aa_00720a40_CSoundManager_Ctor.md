# Review A (reconstruction fidelity): `aa_00720a40` CSoundManager_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00720a40` |
| **VA** | `0x00720a40` |
| **Body** | `0x00720a40`–`0x00720b44` (`ret 4`) |
| **Canonical name** | `CSoundManager_Ctor` (inferred) |
| **Ghidra name** | `FUN_00720a40` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Named_VOGMapText_00720a40` (xref-weak; superseded) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B, W16-N) |
| **Counterpart** | `reviews/B_aa_00720a40_CSoundManager_Ctor.md` |
| **System** | client audio / `CSoundManager` |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_callers`, `get_function_callees` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**In-place constructor** for the process-wide sound manager object.

Authoritative behavior:

1. Install MSVC SEH frame (`LAB_009abdd9`).
2. Initialize a large set of header / float / pointer fields on `param_1` (see §5).
3. Zero **0x32 (50)** dwords starting at `this+0x90` (through `+0x157`).
4. `InitializeCriticalSection(this+0x158)` then `InitializeCriticalSection(this+0x170)`.
5. Set `this[0]=1`, `this[1]=0`, `*(u32*)(this+4)=0`, `*(u32*)(this+8)=0`.
6. Tear down SEH; **return `this`**.

Sole caller (sealed sibling dual `aa_00720d40`):

```text
if ((DAT_00d20200 & 1) == 0) {
  DAT_00d20200 |= 1;
  FUN_00720a40(&DAT_00d20070);
  atexit(LAB_009c3720);
}
return &DAT_00d20070;
```

Family evidence: `CSoundManager::_stopSound` log string at `FUN_00723ab0`.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00720a40_FUN_00720a40.md` | live ≡ decompile |
| Annotated | `docs/reconstruction/raw/aa_00720a40_FUN_00720a40.annotated.md` | field map sealed |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00720a40.cpp` | CF ≡ raw |
| Named clean | `docs/reconstruction/reconstructed-exact/CSoundManager_Ctor.cpp` | same CF |
| Function record | `docs/reconstruction/functions/aa_00720a40_FUN_00720a40.md` | dual sealed |
| Live decompile | Ghidra `0x00720a40` | ≡ raw |
| Live body | `read_memory` entry + epilogue `c40cc20400` | `ret 4` sealed |
| Constant | `read_memory` `0x00aaa668` → `000080bf` = **−1.0f** | sealed |
| GetInstance dual | `A_aa_00720d40_CSoundManager_GetInstance` | sole caller |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| In-place init of caller storage; returns this | **Confirmed** | decomp + GetInstance pass `&DAT_00d20070` |
| `__stdcall` 1 arg (`ret 4`) | **Confirmed** | epilogue bytes |
| `DAT_00aaa668` → `this+0x20` and `+0x24` as −1.0f | **Confirmed** | movss from constant; image bits |
| Zero fill 0x32 dwords @ +0x90 | **Confirmed** | `mov ecx,0x32` / `rep stosd` path |
| CS @ +0x158 and +0x170 | **Confirmed** | two `InitializeCriticalSection` calls |
| Header bytes `[0]=1,[1]=0` late | **Confirmed** | after CS init |
| Gaps (+0x18,+0x2c,…) not written | **Confirmed** | absent from store list |
| Product family `CSoundManager` | **High** | sibling string + GetInstance |
| Exact English name `Ctor` | **Probable** | not PDB |
| Full sizeof / slots ≥ +0x258 | **Open** | methods touch later; BSS for singleton |
| Runtime re-entry | **Open** | once-bit is GetInstance’s job |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH setup | **Yes** |
| Scalar/byte/float field writes | **Yes** (same offsets) |
| 0x32-dword zero loop @ +0x90 | **Yes** |
| ICS ×2 at +0x158 / +0x170 | **Yes** |
| Late header [0]/[1]/+4/+8 | **Yes** |
| Return this; ret 4 | **Yes** |

```text
CSoundManager_Ctor(self):
  SEH
  init fields (table)
  zero self[0x90 .. 0x157]   // 50 dwords
  InitializeCriticalSection(self+0x158)
  InitializeCriticalSection(self+0x170)
  self[0]=1; self[1]=0; *(u32*)(self+4/8)=0
  return self
```

---

## 5. Explicit field writes (seal list)

| Off | Value |
|---|---|
| +0x0c | 0 |
| +0x10 | 1 |
| +0x11…+0x17 | 0 |
| +0x19 | 1 |
| +0x1c | 0.0f |
| +0x20, +0x24 | **−1.0f** (`DAT_00aaa668`) |
| +0x28, +0x30…+0x3c, +0x44…+0x4c, +0x54…+0x5c, +0x64…+0x6c, +0x74…+0x7c | 0 |
| +0x80…+0x8c | 0 |
| +0x90…+0x157 | 0 × 0x32 dwords |
| +0x158 | CRITICAL_SECTION init |
| +0x170 | CRITICAL_SECTION init |
| +0x188 | 0 |
| +0x00 / +0x01 / +0x04 / +0x08 | 1 / 0 / 0 / 0 (late) |

---

## 6. Callers / callees

**Callees:** `InitializeCriticalSection` ×2.

**Callers:** `0x00720d40` only.

---

## 7. Gaps / open

1. Full `CSoundManager` size and semantic names for float slots +0x1c/+0x20/+0x24.
2. Atexit dtor `LAB_009c3720` dual (not OWN).
3. Whether heap-constructed instances exist (xrefs show only static GetInstance path).
4. Runtime / bit-exact not run.

**Verdict:** **accept** — ctor CF, constant, CS geometry, and sole-caller link sealed. Closes residual noted in GetInstance dual (“`FUN_00720a40` full field init dual”).
