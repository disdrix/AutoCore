# Review A (reconstruction fidelity): `aa_007b5dd0` NDUIWindow_BaseCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b5dd0` |
| **VA** | `0x007b5dd0` |
| **Canonical name** | `NDUIWindow_BaseCtor_Inferred` (Ghidra `FUN_007b5dd0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007b5dd0_NDUIWindow_BaseCtor_Inferred.md` |
| **System** | `client-ui` / NDUI base widget |
| **Live tools** | Ghidra `batch_decompile` + `get_function_signature` + callers (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**High.** Base **NDUI window/widget constructor** used as the leaf factory for labels, textures, frames, and as the parent ctor for button/edit/fx/grid subclasses.

Called after `operator_new(0x488)` across CreateChildWidgets bodies (ArenaPrefs / Trade2d / CharSheet2d / NPC mission dialog) and subclass ctors (`FUN_0079c860`, `FUN_00795f20`, `FUN_00864f20`, `FUN_00792d20`).

**Not** XML load, **not** parent-attach, **not** network — pure object init.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b5dd0_FUN_007b5dd0.md` |
| Annotated | `docs/reconstruction/raw/aa_007b5dd0_FUN_007b5dd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007b5dd0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b5dd0_FUN_007b5dd0.md` |
| Live decompile | ≡ raw body (2026-07-29) |

---

## 3. Signature / ABI

```c
// thiscall-style: ECX = widget*, stack/reg param_2 = opaque host/parent cookie
undefined4 * FUN_007b5dd0(undefined4 *param_1 /*this*/, undefined4 param_2);
// returns this
```

| Claim | Confidence | Notes |
|---|---|---|
| Returns `param_1` (this) | **High** | Terminal `return param_1` |
| Sets vtbl `*this = &PTR_FUN_00a960ac` | **High** | first store after base `FUN_00759860` |
| Stores `param_2` at `this+0x290` (`param_1[0xa4]`) | **High** | decompile |
| Size class **0x488** in callers | **High** | CreateChildWidgets `operator_new(0x488)` fan-in |
| MSVC SEH frame | **High** | `LAB_009b327c` |
| 292 insn / 10 BB / CC 5 / 4 calls | **High** | signature |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| SEH + `FUN_00759860()` super-base | Yes | **High** |
| Install base vtbl `PTR_FUN_00a960ac` | Yes | **High** |
| Fill RGBA-style 0xFF quads at `+0x104`×3 and related | Yes | **High CF** |
| Nested object vtbls + `InitializeCriticalSection(this+0x1ec)` | Yes | **High** |
| Global live-count `_DAT_00d17954++` | Yes | **High** |
| Large flag/zero init block (`+0xb8`…, dims, alpha `g_flOne`) | Yes | **High** |
| `operator_new(0x20)` QPC timer helper → `this+0x2b8` (`[0xae]`) | Yes | **High** |
| Screen-metric defaults `DAT_00d1e7a0/a4/d0` → `+0x228/+0x22c/+0x230` | Yes | **High** |
| 10× slot-array clear at `+0x2d8` stride 0x28; 11 dword zero at `+0x45c` | Yes | **High** |
| `param_1[0x3d] \|= 1` flag set | Yes | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = base NDUI window ctor | **High** | vtbl + CreateChildWidgets fan-in + subclass pattern |
| Product C++ class name | **Tentative** | inferred NDUIWindow/CNDUIWindow family |
| Full field map semantics | **Tentative** | many zeros; CS + timer sealed structurally |
| Bit-exact / runtime | **Open** | deferred |

---

## 6. Gaps

1. Exact product class name / RTTI.
2. Meaning of `param_2` cookie beyond storage at `+0x290`.
3. Full layout of CS-protected subobject at `+0x1e8`.
4. Whether clean scaffold renames should replace `FUN_007b5dd0` (plate residual).
