# Review A (reconstruction fidelity): `aa_0091ce80` Client_Camera_ModeDispatchUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091ce80` |
| **VA** | `0x0091ce80` |
| **Body span** | `0091ce80` – `0091d433` (**1459** bytes; `ret 4`) |
| **Canonical name (Ghidra)** | `FUN_0091ce80` |
| **Proposed name** | `Client_Camera_ModeDispatchUpdate_Inferred` (**High** role; product string absent) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W25-B) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred.md` |
| **System** | client camera / mode dispatch tick |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **camera mode dispatcher**: build focus, early-gate, compute ranges, switch on `cam[0x331]` to mode helpers, then post-process look vector + FOV distance band (+ optional velocity FOV).

```
focus = resolveFocus()
if !gate: return
switch mode: modeHelper(...)
look = focus - eye; clamp FOV band; normalize; optional speed FOV
```

**Calling convention:** **EAX = cam*** on entry; one stack float; **`ret 4`**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0091ce80_FUN_0091ce80.md` |
| Annotated | `docs/reconstruction/raw/aa_0091ce80_FUN_0091ce80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0091ce80.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Client_Camera_ModeDispatchUpdate_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred.md` |
| Default helper | `Client_Camera_DefaultModeUpdate_Inferred` @ `0x009168d0` (W24-D) |
| Modes 2/5/7 helper | `Client_Camera_Modes257_ChaseUpdate_Inferred` @ `0x0091b1c0` (W25-B) |

**This pass (live):** `decompile_function` @ `0x0091ce80`; `analyze_function_complete`; `get_function_by_address`; `read_memory` entry/epilog/constants + caller site `0x00924270`. **Not performed:** Launcher, runtime, bit-exact, ledgers. **No** `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 1459 B + `ret 4` | **Confirmed** | epilog `C2 04 00` |
| EAX = cam* (`mov esi,eax`) | **Confirmed** | entry bytes |
| Mode switch table | **Confirmed** | decompile |
| default → dualed `009168d0` | **Confirmed** | W24-D |
| 2/5/7 → dualed `0091b1c0` | **Confirmed** | this wave + call-site EDI |
| FOV band to child `+0xf0` | **High** | decompile |
| Product method name | **Tentative** | `_Inferred` |
| Mode enum English | Open | |
| Containing caller function | Open | undefined Ghidra region ~`0x00923db0` |
| Runtime / bit-exact | Open | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Entry EAX→ESI + stack align | **Yes** |
| Focus prep + pose fallback | **Yes** |
| Map Y pad + gate early return | **Yes** |
| Range pair compute | **Yes** |
| switch mode arms | **Yes** |
| Post look for modes ≠8 | **Yes** |
| Modes 4/5 special Y blend | **Yes** |
| FOV distance band clamp | **Yes** |
| Normalize + `0091b0d0` | **Yes** |
| Optional velocity FOV | **Yes** |

### 4.1 Sealed contract

```
// RET 4; EAX = cam*
void Client_Camera_ModeDispatchUpdate_Inferred(float dt_or_scale);
```

### 4.2 Mode table

| Case | Callee |
|---|---|
| 1 | `FUN_00914930` |
| 2, 5, 7 | `FUN_0091b1c0` |
| 3 | `FUN_00914980` |
| default | `FUN_009168d0` |
| 8 | `FUN_0091c220` |

---

## 5. Gaps (non-blocking)

- Product / PDB method name  
- Mode id English dictionary  
- Dual seals for modes 1/3/8 helpers  
- Containing caller function identity  
- Runtime / bit-exact / diff  

---

## 6. Verdict

**accept-with-gaps** — dispatcher CF + ABI + links to dualed mode helpers sealed; product naming and remaining mode arms open.
