# Review B (skeptical / adversarial): `aa_0087b890` CVOGDialog_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087b890` |
| **VA** | `0x0087b890` |
| **Canonical name** | `CVOGDialog_Ctor` (**product class via RTTI**; method English = ctor role) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0087b890_CVOGDialog_Ctor.md` |
| **System** | missions-progression / shared CVOGDialog base |
| **Live tools** | Independent decompile + `read_memory` + caller sites + RTTI walk |
| **Verdict** | **accept-with-gaps** — accept CF/ABI/RTTI/base-ctor role; reject thiscall-only / mission-only / scaffold-product / terminal claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Ghidra signature `void` / no return | **Falsified** — epilogue `MOV EAX,ESI` before `RET 8`; decompiler returns `param_1` |
| 2 | `__thiscall` ECX-this only | **Falsified** — load `ESI=[esp+0x14]`; no `MOV ESI,ECX`; **`RET 8`** = two stack args |
| 3 | Single stack arg / `RET 4` | **Falsified** — `RET 8`; second dword stored at `+0x2A4` |
| 4 | Mission-progression exclusive helper | **Falsified** — **78** xrefs across dialog installers; partition parent is one consumer only |
| 5 | Mission state / C2S / XML load inside body | **Falsified** — only base call + field zeros + vtbl + store; no strings; no network |
| 6 | Scaffold `Named_CalleeOf_Mission_i_d_npc_xml_0087b890` is product | **Rejected** — parent-seed chain name; RTTI is **CVOGDialog** |
| 7 | Final class vtbl remains `0x00a58c6c` after subclass ctors | **Falsified for subclasses** — e.g. mission host overwrites with `0x00a4a51c`; first-time with `0x00a3d8b4`. This unit installs CVOGDialog base vtbl only. |
| 8 | `param_2` product meaning known | **Rejected** — storage sealed; English open (often 0) |
| 9 | Byte `+0x490` was already 0 from base | **Falsified importance** — base `FUN_00792d20` sets `*(this+0x490)=1`; this body **clears** it — load-bearing override |
| 10 | Runtime / terminal Confirmed | **Rejected** — no Launcher; Terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body 118 B / single BB / RET 8 | **High** | Wrong stack cleanup on port |
| RTTI class CVOGDialog + vtbl 0x00a58c6c | **High** | Wrong type hierarchy |
| Base call FUN_00792d20 first | **High** | Missing subobject init |
| Field zero pack + +0x2A4 store | **High** | Subclass defaults wrong |
| Multi-caller shared dialog base | **High** | Over-narrow system ownership |
| param_2 English | **None** | Misleading port comments |
| Official mode-dword names | **Low** | Layout docs drift |
| Runtime | **Open** | — |

---

## 3. Decompiler pitfalls (must survive port)

1. Do **not** trust Ghidra `void` / empty prototype — port as **returns this**, **two stack args**, **`RET 8`**.
2. Do **not** implement as ECX-thiscall without matching retail call sites (push param; push this; call).
3. Do **not** drop the **`+0x490 = 0`** override — base left it 1.
4. Do **not** treat as mission-host-only or invent mission logic inside this VA.
5. Do **not** claim subclass vtbls are installed here — callers overwrite.
6. Scaffold Mission_i_d_npc_xml alias — **ignore as product symbol**.
7. SEH frame is real (`LAB_009b531d`); leaf port may omit only if exception model matched.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| CVOGDialog constructor (RTTI + vtbl) | Full product method decoration beyond ctor role |
| Stack this + param_2; RET 8; EAX=this | ECX-thiscall / void / RET 4 |
| Base FUN_00792d20 then field pack + vtbl | Mission C2S / XML / widget build |
| Shared base for many dialogs | "missions-only" exclusive unit |
| `_Ctor` structural product class name | Confirmed English for every field |
| Terminal false | Runtime Confirmed |

---

## 5. CF challenge of Review A

- Body bounds + RET 8 + pad: **agree Confirmed**
- RTTI `.?AVCVOGDialog@@` + vtbl install: **agree Confirmed**
- ABI stack-two-arg + return this: **agree Confirmed**
- Multi-caller shared base (not mission-only body): **agree Confirmed**
- accept-with-gaps (not bare accept): **agree** — param_2 English + mode names + runtime residual is real

**Verdict:** **accept-with-gaps**
