# Review A (reconstruction fidelity): `aa_0075f7f0` GfxDevice_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075f7f0` |
| **VA** | `0x0075f7f0`–`0x0075fb87` exclusive (**919 B** / `0x397`) |
| **Canonical name** | `GfxDevice_Ctor_Inferred` |
| **Ghidra name** | `FUN_0075f7f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-R) |
| **Counterpart** | `reviews/B_aa_0075f7f0_GfxDevice_Ctor_Inferred.md` |
| **System** | client / Palantir graphics (`gfxAdapter.cpp` CreateDevice host) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `get_function_by_address` + xrefs + callees + `read_memory` (entry/epilogue) + sole-caller decompile `FUN_00735c90`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete placement ctor of the **0x7b0** graphics-device host allocated after D3D `CreateDevice` succeeds in adapter setup (`C:\vog\1_code\palantir\palantir\graphics\gfxAdapter.cpp`):

1. SEH `LAB_009b271b`; publish `DAT_00d1f044 = self`.
2. `self+0 = device9*`; `self+4 = d3d9*` (ECX); zero `+8/+c/+10`.
3. `FUN_00966690()` early init; zero high dword cluster `@+0x73C…` and flags `@+0x7A8`.
4. **AddRef** on d3d9 (`vtbl+4`).
5. Zero **D3DCAPS9-sized** blocks: `+0x14` and `+0x144` (**0x4c** dwords each = **0x130**).
6. Zero present-params span `+0x2B8` (**0xe** dwords = **0x38**).
7. Zero large bank `+0x2F0` (**0x113** dwords) + mid cluster `@+0x774…`.
8. Heap-construct **14 subsystem slots** `@+0x73C…+0x770` (several dual-published as `DAT_00d1f6xx`).
9. Return **self** (`RET 8`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-R) | `docs/reconstruction/raw/aa_0075f7f0_FUN_0075f7f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075f7f0_FUN_0075f7f0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/GfxDevice_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075f7f0.cpp` |
| Function records | `functions/aa_0075f7f0_FUN_0075f7f0.md`, `functions/aa_0075f7f0_GfxDevice_Ctor_Inferred.md` |
| Related | W34-F NestedHash 0x30 @ slot; W33-R PoolHost at `DAT_00d1f624`; gfxAdapter sole caller |
| Live | body bounds 0x397; epilogue `C2 08 00`; sole xref `FUN_00735c90` @ `0x00736489`; `operator_new(0x7b0)` |

---

## 3. Signature (sealed)

```c
// ECX = IDirect3D9* (stored + AddRef'd at self+4)
// stack: self* (0x7b0), IDirect3DDevice9*; RET 8; returns self
// Note: "this" is NOT the constructed object (MSVC thiscall on D3D9 / adapter side).
void *__thiscall GfxDevice_Ctor_Inferred(void *d3d9, void *self, void *device9);
```

| Formal | Source | Conf |
|---|---|---|
| d3d9 | ECX → `self+4` + `AddRef` | **High** |
| self | first stack (`8B 6C 24 24` → EBP) | **High** |
| device9 | second stack → `*self` | **High** |
| return | self | **High** |
| cleanup | `RET 8` | **High** |

---

## 4. Subsystem slot map (self dword index → offset)

| Slot idx | Off | Size | Global / init |
|---|---|---|---|
| `0x1cf` | `+0x73C` | `0x20` | `DAT_00d1f624` — zero fields (**PoolHost** seed) |
| `0x1d0` | `+0x740` | `0xC4` | `FUN_0073bfd0` |
| `0x1d1` | `+0x744` | `0x5C` | `DAT_00d1f630` — zero fields |
| `0x1d2` | `+0x748` | `1` | `DAT_00d1f654` — bare `new(1)` |
| `0x1d3` | `+0x74C` | `0x20` | `FUN_00986d40` |
| `0x1d4` | `+0x750` | `0x20` | `FUN_00985df0` |
| `0x1d5` | `+0x754` | `0x34` | `FUN_0096eec0` (embeds NestedHash 0xC) |
| `0x1d6` | `+0x758` | `0x28` | `DAT_00d1f628` + `NestedHash_Ctor_Sentinel0x30` (W34-F) |
| `0x1d7` | `+0x75C` | `0x20` | `FUN_00966f70` |
| `0x1d8` | `+0x760` | `0x150` | `FUN_00969df0` |
| `0x1d9` | `+0x764` | `0x48` | `FUN_0073e3a0` |
| `0x1da` | `+0x768` | `0x5C` | `FUN_0073c150` |
| `0x1db` | `+0x76C` | `0x10` | `DAT_00d1f620` — zero fields |
| `0x1dc` | `+0x770` | `0x1C` | `FUN_00987260` |

Post-ctor sole caller copies **D3DCAPS** into `+0x14` / `+0x144` and present params into `+0x2B8` (ctor only zeroes those ranges).

---

## 5. Control flow (clean ≡ raw ≡ live)

```
SEH LAB_009b271b
DAT_00d1f044 = self
*self = device9; self+4 = d3d9; zero +8/+c/+10
FUN_00966690
zero high ptrs @+0x73C…+0x770 region + flags
AddRef(d3d9)
zero caps×2 (0x130), present(0x38), bank(0x44C), mid cluster
new+init each subsystem slot (null-safe)
return self; RET 8
```

| Stage | Match | Conf |
|---|---|---|
| Body 0x397 / RET 8 | **Yes** | **High** |
| Size 0x7b0 factory | **Yes** | **High** |
| Sole CreateDevice caller | **Yes** | **High** |
| PoolHost global seed | **Yes** (`DAT_00d1f624`) | **High** |
| NestedHash 0x30 slot | **Yes** (W34-F) | **High** |

---

## 6. Gaps

- Product / MSVC demangle for gfx device class (scaffold chain is parent-seed noise).
- Full English for each subsystem slot ctor (`FUN_0073bfd0`, `FUN_00986d40`, …).
- Exact role of `FUN_00966690` early init.
- Runtime / bit-exact / differential.

---

## 7. Verdict

Fidelity pass seals complete device-host ctor role, ABI (ECX=d3d9, stack self+device, RET 8), 0x7b0 size, zero ranges, global/pool seed, and sole gfxAdapter wiring. Residual product/slot English → **accept-with-gaps**.
