# Review A (reconstruction fidelity): `aa_004cda90` Client_InitPalantirViewBundle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cda90` |
| **VA** | `0x004cda90`–`0x004cdc34` exclusive (**420 B** / `0x1A4`) |
| **Canonical name** | `Client_InitPalantirViewBundle_Inferred` |
| **Ghidra name** | `FUN_004cda90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-F) |
| **Counterpart** | `reviews/B_aa_004cda90_Client_InitPalantirViewBundle_Inferred.md` |
| **System** | client / Palantir graphics + env bootstrap |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Factory on large client/core parent (sole caller `FUN_00948530` window init):

1. `new(0x150)` + GfxView ctor `FUN_0075ceb0` → `+0xE890`; near **0.5f** / far **1000|500**.
2. Optional Palantir desktop wire via `+0xE89C`.
3. `new(0x198)` + `FUN_00492dd0(0,parent)` → `+0xE894`.
4. `new(0xC8)` + `Class_009c7a1c_Ctor` → `+0xE898`.
5. Cross-wire view↔env; `FUN_0048fc90(1)`; publish `*(env+4)` → `DAT_00d1a54c`.
6. Return **1**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-F) | `docs/reconstruction/raw/aa_004cda90_FUN_004cda90.md` |
| Annotated | `docs/reconstruction/raw/aa_004cda90_FUN_004cda90.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_InitPalantirViewBundle_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cda90.cpp` |
| Function records | `functions/aa_004cda90_FUN_004cda90.md`, `functions/aa_004cda90_Client_InitPalantirViewBundle_Inferred.md` |
| Related | `Class_009c7a1c_Ctor` W29-G (sole factory context) |
| Live | decompile ≡ raw 2026-07-23; entry SEH+`push 0x150`; epilogue `B0 01`…`C3`; float DAT bytes |

---

## 3. Signature (sealed)

```c
// __thiscall/__fastcall; ECX=parent*; returns 1; bare RET
uint32_t __fastcall Client_InitPalantirViewBundle_Inferred(void *parent);
```

| Formal | Source | Conf |
|---|---|---|
| parent | ECX (`8B F1`) | **High** |
| return | AL=1 (`B0 01`) | **High** |
| cleanup | bare `C3` + `ADD ESP,0x10` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
SEH LAB_009a1ef7
new(0x150)+FUN_0075ceb0 → +0xE890
view: +0xF0=0.5f; +0xF4=1000|500 by parent+0x7d
if +0xE89C: wire desktop + vcall + stamp 0xFF000000
new(0x198)+FUN_00492dd0(0,parent) → +0xE894
new(0xC8)+FUN_00496f70(parent) → +0xE898
view+4=env; env+0xC0=view
FUN_0048fc90(env,1)
toggle DAT_00d1a54c via FUN_0074e200; store *(env+4)
return 1
```

| Stage | Match | Conf |
|---|---|---|
| Three alloc sizes 0x150/0x198/0xC8 | **Yes** | **High** |
| Store offsets E890/E894/E898 | **Yes** | **High** |
| Float constants 0.5 / 1000 / 500 | **Yes** (bytes) | **High** |
| Sole caller Palantir path | **Yes** | **High** |
| Cross-wire + global publish | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `6A FF 68 F7 1E 9A 00` … `68 50 01 00 00 8B F1` (push 0x150) |
| Mid | `68 00 00 00 3F` (0.5f); `80 7E 7D 00` (test parent+0x7d) |
| Epilogue | `89 35 4C A5 D1 00 B0 01 5E` … `83 C4 10 C3` |
| Size | **420 B** exclusive end `0x004cdc34` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product / MSVC demangle for parent type and `FUN_00492dd0` class.
- Semantic labels for `+0x7d`, `DAT_00d1a54c`, `FUN_0074e200`.
- Desktop vcall slot product identity.
- Runtime / bit-exact / differential — open.

---

## 7. Verdict

CF, ABI, three factory arms, float stamps, sole caller, and cross-wire sealed → **accept-with-gaps** (product English residual).
