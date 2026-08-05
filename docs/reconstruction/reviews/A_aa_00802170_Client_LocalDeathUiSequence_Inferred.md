# Review A (reconstruction fidelity): `aa_00802170` Client_LocalDeathUiSequence_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00802170` |
| **VA** | `0x00802170` |
| **Canonical name** | `Client_LocalDeathUiSequence_Inferred` |
| **Ghidra name** | `FUN_00802170` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00802170_Client_LocalDeathUiSequence_Inferred.md` |
| **System** | client combat / death / respawn UI |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Local-player death UI orchestration** on client (`__fastcall` `this` in ECX).

Outer gate (all must hold):

1. `*(byte*)(this + 0xaa) != 0` — local/death-eligible flag
2. `*(byte*)(DAT_00d1b6d8 + 0x4f1) == 0` — global mode flag clear
3. `*(this + 0xe98) != 0` — local character/object present
4. Either no drive-body at `e98+0x250`, or drive flag bit **10** at body `+0x180` clear
5. `*(byte*)(DAT_00d1b644 + 0xf6) == 0`

Then sequence:

| Step | Action |
|---|---|
| Optional | If `this+0x10ac` has `+0x590`, `FUN_0083c7b0` |
| Clear | `*(host+0xf38 + 0x758) = 0` if host present |
| UI | If `this+0x10f0` visible → `vtbl+0x448` |
| Teardown | `FUN_007fc970`, `FUN_007fbbb0`, `FUN_0093e120(0)` |
| Dialogs | Walk **0x3a** slots at `+0x1030`; if visible and exclusive (`[0x140]==1`) → `FUN_007fca10` |
| Tip | `Client_MaybeShowFirstTimeTip(7)` |
| FX | If `this+0x3c10`: `FUN_0048a780("LED_FX\\LED_FX_death.xml", …)` |
| Death UI widgets | If `+0x1158` and `+0x114c` set: show/fade widgets `+0x1150`, `+0x1154`, `+0x114c`, `+0x1158` via host `+0xf40` `vtbl+0xa8` / widget `+0xfc(1, 1.5f)` / `+0xd4(1)`; `FUN_0040ada0`; host `+0x3f4(1)`; host `+0xf38` `+0x3c4(1)`; `FUN_0092f000`; character `vtbl+0x1ac`; `FUN_007fb4a0` |
| Heartbeat | If `this+0xd38` list: `new(0x24)` → `FUN_005b3210(char, 300000)` → `CVOGHBList_Enqueue` + `CVOGHBBase_Start` |

Callers: `Client_RecvDestroyObject`, residual `FUN_009440e0`, `FUN_009580d0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00802170_*`, `reconstructed-exact/FUN_00802170.cpp` |
| Function record | `functions/aa_00802170_FUN_00802170.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00802170` (2026-07-29) |
| Callees | close family, tip, LED FX, HB enqueue/start |
| String/path | `LED_FX\\LED_FX_death.xml` via `PTR_s_LED_FX_LED_FX_death_xml_00b00258` |
| Constant | fade float `0x3fc00000` = **1.5f**; HB delay **300000** ms |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Death/local UI sequence (not server loot) | **Confirmed** | LED_FX_death + tip 7 + destroy callers |
| Outer multi-flag gate | **Confirmed** | decompile |
| Closes exclusive dialogs via 007fca10 | **Confirmed** | table walk |
| Death widget show/fade block gated on 1158+114c | **Confirmed** | |
| HB action 300000 ms enqueued | **Confirmed** | |
| Exact meaning of +0xaa / DAT flags | **Tentative** | roles inferred |
| Product name of HB ctor 005b3210 | **Open** | |
| clean ≡ raw ≡ live | **High** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Outer gate | Yes |
| Clear host field / optional 10f0 | Yes |
| Teardown trio + dialog sweep | Yes |
| Tip 7 + death LED FX | Yes |
| Widget fade block | Yes |
| Optional HB enqueue | Yes |

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `Client_RecvDestroyObject` | destroy may trigger local death UI |
| Caller | `FUN_009440e0`, `FUN_009580d0` | residual client paths |
| Callee | `FUN_007fca10` | close exclusive dialogs |
| Callee | `Client_MaybeShowFirstTimeTip(7)` | death tip |
| Callee | `FUN_0048a780` | death LED FX |
| Callee | `CVOGHBList_Enqueue` / `CVOGHBBase_Start` | delayed HB |
| Callee | `FUN_005b3210` | HB action ctor (300000) |

---

## 6. Gaps / open

1. Name `FUN_005b3210` HB (death timer / respawn enable?).
2. Semantics of global `DAT_00d1b6d8+0x4f1` and `DAT_00d1b644+0xf6`.
3. Which destroy paths set `+0xaa` before call.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — death UI sequence CF sealed; flag English Open.
