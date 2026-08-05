# Review A (reconstruction fidelity): `aa_00578b30` Skill_HB_FireTail_FxTargetAndPeriodStamp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578b30` |
| **VA** | `0x00578b30`–`0x00578cda` |
| **Canonical name** | `Skill_HB_FireTail_FxTargetAndPeriodStamp` (**INFERRED** structural) |
| **Prior scaffold** | `FUN_00578b30` |
| **Review date** | `2026-07-29` (W21-C OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_00578b30_Skill_HB_FireTail_FxTargetAndPeriodStamp.md` |
| **System** | skills-abilities / heartbeat |
| **Verdict** | **accept-with-gaps** — ABI, period seal, FX event, CF sealed; nested attach args + product English open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + string). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Shared **skill HB fire tail** (multi-caller):

1. Empty hook `FUN_004648a0` via `PTR_FUN_00af31e4`.
2. `CVOGReaction_ResolveObjectTarget` from skill target fields.
3. Owner path: flag`0x10` → `owner+0x26++`; `FxCache_EnsureMasterAndResolve(skillKey@+0x620, 0x16, 1)` with host from global; attach FX via vtbl+`0xf8`; mission-fail notify + zeroed `FUN_004b7e50`.
4. Target path: vtbl+`0x214` + flag`0x02` → `FUN_00518ca0`; char@`+0x140` + vtbl+`0x210` → `FUN_0051f880(1)`.
5. Period finalize:
   - `sentinel(+0x0C)==-1000 && periodMs(+0x08)==0` → `Stop` + `StampLastFireTime` + return.
   - `sentinel!=1 && periodMs<300` → log `"Skill %d has invalid frequency %d"`; clamp period to **300**.
   - Else/fallthrough: `StampLastFireTime`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00578b30_FUN_00578b30.md` (+ W21-C live section) |
| Annotated | `docs/reconstruction/raw/aa_00578b30_FUN_00578b30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_FireTail_FxTargetAndPeriodStamp.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00578b30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00578b30_Skill_HB_FireTail_FxTargetAndPeriodStamp.md` |
| Live decompile | `decompile_function` `0x00578b30` — **≡** raw |
| Live bytes | `read_memory` prolog + period tail + string `0x009d4030` |
| Callers | `get_function_callers` (8 sites) |
| Callees | `get_function_callees` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| ECX → ESI this | `8B F1` |
| No stack args | plain RET after pops |
| Epilogue | `5F 5E 5D 5B 59 C3` |
| Body | Ghidra `00578b30`–`00578cda` |

### 3.2 Period contract — **SEALED**

| Fact | Evidence |
|---|---|
| Load sentinel `[ESI+0x0C]` | `8B 46 0C` |
| Compare −1000 | `3D 18 FC FF FF` |
| Gate periodMs `[ESI+0x08]==0` | `83 7E 08 00` |
| Stop then Stamp on one-shot | calls `0x005081d0`, `0x00508270` |
| Clamp gate `sentinel!=1` | `83 F8 01` / `74` |
| Floor 300 (`0x12C`) | `3D 2C 01 00 00` + `C7 46 08 2C 01 00 00` |
| Log skillKey@`+0x620` + period | push `[esi+0x620]`, `[esi+0x08]`, string `0x009d4030` |

### 3.3 FX / flags — **SEALED role**

| Fact | Evidence |
|---|---|
| Event args `0x16`, `1` | `6A 01 6A 16` before `FUN_005408f0` |
| skillKey from `+0x620` | `8B 86 20 06 00 00` |
| Host ECX from `DAT_00b041fc` | `8B 0D FC 41 B0 00` |
| Flag test `+0x639` bit `0x10` / `0x02` | `F6 86 39 06 00 00 10/02` |
| owner+0x26 increment | `80 40 26 01` pattern after test |

### 3.4 Three-rep CF fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline |
| Live re-decompile 2026-07-29 | **≡** raw |
| Bytes (period/FX/epilogue) | **≡** |

---

## 4. Naming

| Name | Status |
|---|---|
| `Skill_HB_FireTail_FxTargetAndPeriodStamp` | **Structural inferred** (multi-caller fire tail) |
| `FUN_00578b30` | scaffold alias |
| PDB product name | **Open** |

---

## 5. Gaps

1. Exact ResolveObjectTarget arg packing / possible this from `[*(this+0x688)+0xe4e8]`.
2. Nested vtbl+0xf8 call arg completeness (decomp shows empty `()` on else arm — register residual risk).
3. Semantics of `owner+0x26`, flags@`+0x639`, char@`+0x140`.
4. `FUN_00518ca0` / `FUN_0051f880` contracts (not owned).
5. Runtime / bit-exact / differential — open.

---

## 6. AutoCore port notes

- Port period floor **300 ms** and one-shot (`sentinel==-1000 && period==0` → stop) exactly.
- Do not treat Ghidra `CVOGHBBase*` array overlay as true layout past `+0x27`.
- FX event **0x16** is part of the sealed surface for this tail.

**Verdict:** **accept-with-gaps**
