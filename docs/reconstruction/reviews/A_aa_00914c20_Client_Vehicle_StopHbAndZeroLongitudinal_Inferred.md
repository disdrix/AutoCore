# Review A (reconstruction fidelity): `aa_00914c20` Client_Vehicle_StopHbAndZeroLongitudinal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00914c20` |
| **VA** | `0x00914c20`–`0x00914c59` inclusive (**58 B** / `0x3A`) |
| **Canonical name** | `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` (Ghidra `FUN_00914c20`) |
| **Prior scaffold** | `FUN_00914c20` (2026-07-23 partial) |
| **Review date** | `2026-08-05` (OWN-ONLY dual A/B **MEGA-098** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ entry bytes) |
| **Counterpart** | `reviews/B_aa_00914c20_Client_Vehicle_StopHbAndZeroLongitudinal_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create/seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` / `analyze_function_complete` / `disassemble_function` / `get_function_callers` / `get_xrefs_to` / `read_memory` @ entry + call sites. Prefer decompile/`read_memory`. Own VA only. No ledgers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Short **client vehicle drive-clear helper**: when soft/mode flag `DAT_00d1a860` is non-zero and the client host holds a heartbeat object at `+0xc70`, clear latch `+0xa35`, **Stop** that HB, and if a local vehicle is present force **longitudinal axis to 0**.

**Live decompile (`0x00914c20`, 2026-08-05):**

```c
void FUN_00914c20(void)
{
  int in_EAX;   // client / game host (EAX at entry)

  if ((DAT_00d1a860 != '\0') && (*(int *)(in_EAX + 0xc70) != 0)) {
    *(undefined1 *)(in_EAX + 0xa35) = 0;
    FUN_005081d0();                        // CVOGHBBase_Stop (ECX = HB)
    if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) {
      VehicleEntity_SetLongitudinalInput(0);
    }
  }
  return;
}
```

≡ frozen raw (2026-07-23) CF; ≡ annotated refresh; ≡ clean.

**Entry bytes (`read_memory` len 58):**

```text
803d60a8d1000074308b88700c000085c97426c680350a000000e89135bfffa1d8b6d10085c074118b885002000085c974076a00e8f709beffc3
```

```text
0x00914c20: cmp  byte ptr [DAT_00d1a860], 0
0x00914c27: jz   exit
0x00914c29: mov  ecx, [eax+0xc70]      ; HB object
0x00914c2f: test ecx, ecx
0x00914c31: jz   exit
0x00914c33: mov  byte ptr [eax+0xa35], 0
0x00914c3a: call CVOGHBBase_Stop       ; 0x005081d0
0x00914c3f: mov  eax, [DAT_00d1b6d8]
0x00914c44: test eax, eax
0x00914c46: jz   exit
0x00914c48: mov  ecx, [eax+0x250]      ; vehicle
0x00914c4e: test ecx, ecx
0x00914c50: jz   exit
0x00914c52: push 0
0x00914c54: call VehicleEntity_SetLongitudinalInput  ; 0x004f5650
0x00914c59: ret
```

Relative calls sealed: `E8…` @ `00914c3a` → `005081d0`; @ `00914c54` → `004f5650`.

---

## 2. Inspected artifacts

| Artifact | Path / tool | This pass |
|---|---|---|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00914c20_FUN_00914c20.md` | ≡ live CF |
| Annotated | `docs/reconstruction/raw/aa_00914c20_FUN_00914c20.annotated.md` | refreshed |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_Vehicle_StopHbAndZeroLongitudinal_Inferred.cpp` | CF match |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00914c20.cpp` | CF match |
| Function records | `functions/aa_00914c20_FUN_00914c20.md` + named | sealed |
| Live decompile | Ghidra `0x00914c20` | **≡ raw** |
| Live bytes | `read_memory` 58 B @ entry | gate + Stop + SetLong0 |
| Live xrefs | `get_xrefs_to` / analyze | **2** sites |
| Call-site bytes | `read_memory` @ `00914ca0` / `00925970` | both `MOV EAX,EDI` |

**Not performed:** Launcher, runtime golden, package bit-exact, Ghidra product rename.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `00914c20`–`00914c59` (58 B) | **High** | `get_function_by_address` + RET + CC pad |
| Gate: `DAT_00d1a860 != 0` && `*(host+0xc70) != 0` | **High** | decompile ≡ asm |
| Clear `host+0xa35 = 0` before Stop | **High** | `c6 80 35 0a 00 00 00` |
| `CVOGHBBase_Stop` thiscall ECX=HB | **High** | ECX loaded from `[EAX+0xc70]`; dual-sealed callee |
| `SetLongitudinalInput(0)` ECX=vehicle | **High** | `push 0; call 004f5650`; dual-sealed callee |
| Host in **EAX** (not ECX thiscall) | **High** | both callers `MOV EAX,EDI` before CALL |
| Bare `RET` (no stack cleanup) | **High** | `C3` @ `00914c59` |
| Exactly **2** call sites | **High** | xrefs + analyze |
| No HB / steer / Push in body | **High** | 2 calls only |
| Product English (`DAT_00d1a860`, `+0xa35`) | **Open** | `_Inferred` |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Mode flag + HB ptr gate | **Yes** |
| Order: latch clear → Stop → optional SetLong(0) | **Yes** |
| Early no-op if gate fails | **Yes** |
| No thr/steer/HB-engage stores | **Yes** |
| Optional vehicle path independent of latch | **Yes** (vehicle gated separately) |

### 4.1 Contract

```
require DAT_00d1a860 && host=EAX && *(host+0xc70) != 0
*(u8*)(host+0xa35) = 0
CVOGHBBase_Stop(ECX=*(host+0xc70))
if DAT_00d1b6d8 && vehicle=*(+0x250):
  VehicleEntity_SetLongitudinalInput(ECX=vehicle, 0)
return
```

---

## 5. Call graph (owned leaf only)

```text
FUN_00914c60  [residual scaffold]
  └─ CALL 00914c20 @ 00914ca5   MOV EAX,EDI

Client_InteractWorldClickHub  FUN_00925820  [dualed W17-C]
  ├─ (inline equivalent CF early — not this unit)
  └─ CALL 00914c20 @ 00925984   MOV EAX,EDI  (drop-destroy modal path)

FUN_00914c20  Client_Vehicle_StopHbAndZeroLongitudinal_Inferred  [OWN MEGA-098]
  ├─ CVOGHBBase_Stop                     0x005081d0  [dual accept]
  └─ VehicleEntity_SetLongitudinalInput  0x004f5650  [dual sealed]
```

---

## 6. Gaps / open

1. Product English for `DAT_00d1a860` and latch `+0xa35` (shared open with hub dual).
2. Whether `+0xc70` is always base HB vs subclass timer (Stop contract uses `+0x21` fDormant).
3. Sibling residual `FUN_00914c60` not dualled here (OWN-ONLY this VA).
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps** — CF/ABI/RET/callers/callees sealed; product names + runtime open.
