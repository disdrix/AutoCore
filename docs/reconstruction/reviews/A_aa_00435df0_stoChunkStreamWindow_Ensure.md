# Review A (reconstruction fidelity): `aa_00435df0` stoChunkStreamWindow_Ensure

| Field | Value |
|---|---|
| **Stable ID** | `aa_00435df0` |
| **VA** | `0x00435df0`–`0x00435f24` |
| **Canonical name** | `stoChunkStreamWindow_Ensure` |
| **Prior scaffold** | `FUN_00435df0` |
| **Review date** | `2026-07-29` (W18-A OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_00435df0_stoChunkStreamWindow_Ensure.md` |
| **System** | storage / arda2 `stoChunk` |
| **Verdict** | **accept-with-gaps** — ABI, three-arm CF, window map, memmove+vcalls sealed; product English + streamEnd name open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + IAT) + `get_function_by_address` / xrefs / callees. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Reposition a stoChunk **stream window** so the absolute stream position `absPos` sits at **buffer base** (`cursor=0`), then refill from the bound **source** object:

1. Optionally **slide** existing buffer contents (forward or backward) when the new base overlaps the current window.
2. Else **full** Seek + Read.
3. Clamp `available = min(capacity, streamEnd - base)`.
4. Propagate **Read** status in **EAX** (callers treat `< 0` as failure).

Primary call shape from sibling readers: `Ensure(window, base + cursor)` when `available` is short of the needed span.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00435df0_FUN_00435df0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00435df0_FUN_00435df0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkStreamWindow_Ensure.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00435df0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00435df0_stoChunkStreamWindow_Ensure.md` |
| Live decompile | `decompile_function` `0x00435df0` — **≡** raw |
| Live bytes | `read_memory` `0x00435df0` length 320 — three `c2 04 00` exits + `cc` pad |
| Callee | callees → `memmove`; IAT dword `0x009c652c` |
| Sibling context (not owned) | ReadHeader16 `0x004368b0`; bulk `0x00435f30`; OpenChunk |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Window in **ECX** | prolog `mov esi,ecx` pattern in bytes (`8b f1`) |
| Stack arg0 = absPos | `mov edi,[esp+0x14]` after pushes; sibling `push base+cursor; call` |
| Epilogue | **`ret 4`** (`c2 04 00`) all three returns |
| Body range | Ghidra `00435df0`–`00435f24` |
| Return surface | decomp `void`; callers `if (hr < 0)` — **EAX = last Read** |

```c
int32_t __thiscall stoChunkStreamWindow_Ensure(StoStreamWindow* this, int32_t absPos);
```

### 3.2 Window offsets — **SEALED** (English on +0x14 Probable)

| Rel | Role | Conf |
|---:|---|---|
| `+0x00` | `pSource*` | **High** |
| `+0x04` | cursor → **0** | **High** |
| `+0x08` | base → absPos | **High** (sibling ReadHeader16) |
| `+0x0c` | available | **High** |
| `+0x10` | capacity (clamp / arm-B gate) | **High** |
| `+0x14` | streamEnd for `min(cap, end-base)` | **High** use / **Probable** name |
| `+0x18` | buffer | **High** |

### 3.3 Three arms — **SEALED**

| Arm | Gate | Action summary |
|---|---|---|
| **A** | `base <= absPos < base+available` | memmove keep-suffix left; Seek(absPos+keep); Read tail |
| **B** | `absPos < base` ∧ `base <= capacity+absPos` | memmove shift right; Seek(absPos); Read front gap `oldBase-absPos` |
| **C** | else (`LAB_00435ee4`) | base=absPos; Seek(absPos); Read full available |

### 3.4 Virtual source ops — **SEALED** (English INFERRED)

| Slot | Args | Role |
|---:|---|---|
| `*pSource.vtbl + 4` | `(pos, 0)` | Seek-like; **result discarded** |
| `*pSource.vtbl + 0x14` | `(dst, size)` | Read-like; **return status** |

### 3.5 Three-rep CF fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline |
| Live re-decompile 2026-07-29 | **≡** raw |
| Bytes | `ret 4`, memmove IAT, three arms |

---

## 4. Call graph (inventory)

| Direction | Symbol | VA | Note |
|---|---|---|---|
| Callee | `memmove` | IAT | buffer slide |
| Callee | source vtbl+4 / +0x14 | virtual | Seek / Read |
| Caller | `stoChunkStreamWindow_ReadHeader16` | `0x004368b0` | ensure when short |
| Caller | `stoChunkReader_OpenChunk` | `0x0076a2c0` | ×2 sites |
| Caller | many typed readers / bulk | various | 50+ xrefs |

---

## 5. Gaps / open

1. Product/PDB English for this helper and source vtbl slots.
2. Precise `streamEnd` (+0x14) semantics when length unknown / unbounded.
3. Seek failure visibility (discarded; only Read status returns).
4. Runtime / bit-exact / differential — open.

---

## 6. Verdict

**accept-with-gaps** — ensure contract sealed at High CF for ports; naming of streamEnd/Seek/Read remains inferred.
