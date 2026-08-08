# Review A (reconstruction fidelity): `aa_00636cc0` CVOGHBMoveVehicle_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636cc0` |
| **VA** | `0x00636cc0` |
| **Body span** | `0x00636cc0`–`0x00636d07` inclusive (**72** bytes; exclusive end `0x00636d08` → `cc…` then dtor) |
| **Canonical name** | `CVOGHBMoveVehicle_OnHeartBeat` |
| **Ghidra name** | `FUN_00636cc0` |
| **Review date** | `2026-08-05` (OWN-ONLY **R11-023**) |
| **Reviewer role** | Independent reconstruction review (clean ≡ machine ≡ live decompile CF; decompiler arg bind superseded) |
| **Counterpart** | `reviews/B_aa_00636cc0_CVOGHBMoveVehicle_OnHeartBeat.md` |
| **System** | `input-drive-control` / heartbeat OnHeartBeat |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_xrefs` / `get_function_callers` + `read_memory` (body, vtbl, globals, ctor constants). **No** `disassemble_bytes`. **No** Launcher.

---

## 1. Purpose

Virtual **OnHeartBeat** for **`CVOGHBMoveVehicle`**: each pulse, drive the bound vehicle entity toward its aim via **`MoveToTarget3DPoint`**; if that returns false, **`CVOGHBBase_Stop`** (which may park steer via dualed OnEnd). Writes an out-status dword for TryFire.

**Machine proof (`disassemble_function` + `read_memory` len 80 @ entry):**

```text
0x00636cc0:  56                   push  esi
0x00636cc1:  8B F1                mov   esi, ecx
0x00636cc3:  8B 4E 24             mov   ecx, [esi+0x24]   ; entity*
0x00636cc6:  85 C9                test  ecx, ecx
0x00636cc8:  75 10                jnz   0x00636cda
0x00636cca:  8B 0D 84 4F AF 00    mov   ecx, [0x00af4f84] ; =1
0x00636cd0:  8B 44 24 08          mov   eax, [esp+0x8]
0x00636cd4:  89 08                mov   [eax], ecx
0x00636cd6:  5E                   pop   esi
0x00636cd7:  C2 04 00             ret   4
0x00636cda:  8B 56 34             mov   edx, [esi+0x34]
0x00636cdd:  8B 46 30             mov   eax, [esi+0x30]
0x00636ce0:  6A 01                push  1
0x00636ce2:  52                   push  edx
0x00636ce3:  8B 56 2C             mov   edx, [esi+0x2c]
0x00636ce6:  50                   push  eax
0x00636ce7:  52                   push  edx
0x00636ce8:  E8 63 59 EC FF       call  0x004fc650   ; MoveTo; ECX=entity
0x00636ced:  84 C0                test  al, al
0x00636cef:  75 07                jnz   0x00636cf8
0x00636cf1:  8B CE                mov   ecx, esi
0x00636cf3:  E8 D8 14 ED FF       call  0x005081d0   ; Stop
0x00636cf8:  8B 0D 60 2C D0 00    mov   ecx, [0x00d02c60] ; =0
0x00636cfe:  8B 44 24 08          mov   eax, [esp+0x8]
0x00636d02:  89 08                mov   [eax], ecx
0x00636d04:  5E                   pop   esi
0x00636d05:  C2 04 00             ret   4
```

Hex: `568bf18b4e2485c975108b0d844faf008b44240889085ec204008b56348b46306a01528b562c5052e86359ecff84c075078bcee8d814edff8b0d602cd0008b44240889085ec20400`

Call targets: rel32 decode → `004fc650`, `005081d0` (**High**).

**Calling convention:** MSVC `__thiscall` — HB in **ECX**; stack **pOutStatus**; **`RET 4`**.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00636cc0_FUN_00636cc0.md` | R11-023 append (body retained) |
| Annotated | `docs/reconstruction/raw/aa_00636cc0_FUN_00636cc0.annotated.md` | Refresh |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_OnHeartBeat.cpp` | New |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00636cc0.cpp` | Replaced scaffold |
| Function FUN | `docs/reconstruction/functions/aa_00636cc0_FUN_00636cc0.md` | Updated |
| Function named | `docs/reconstruction/functions/aa_00636cc0_CVOGHBMoveVehicle_OnHeartBeat.md` | New |
| Live decompile | Ghidra `0x00636cc0` | CF if/call ≡; **MoveTo this wrong** |
| Live bytes | `read_memory` | ≡ instruction map |
| Live xrefs | DATA `009e3b7c` / `009d559c` only | no code callers |
| Parent OnEnd dual | `aa_00636ba0` | RTTI + entity@+0x24 + Stop chain |
| Ctor context | `FUN_00636bd0` | entity → +0x24; field defaults |
| Callee duals | MoveTo verified; Stop dualed | siblings |
| Partition | `WAVE_2026-08-05_r11_residual_partition_map.md` | R11-023 |

**Not performed:** Launcher, runtime golden, bit-exact package diff, dual of ctor `00636bd0` / sibling `00636d10`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 72 B / end `0x00636d07` | **High** | bytes + next `cc` / dtor `00636d10` |
| `this` in ECX (HB) | **High** | `MOV ESI,ECX` |
| Gate on `[this+0x24] == 0` | **High** | TEST/JNZ |
| MoveTo ECX = entity@+0x24 | **High** | ECX live; not reloaded before call |
| Stack: accept@+0x2c, cruise@+0x30, aim@+0x34, rev=1 | **High** | push order |
| Stop only when AL==0 | **High** | TEST AL / JNZ skip |
| Stop ECX = HB (ESI) | **High** | `MOV ECX,ESI` |
| Out 1 / 0 from globals | **High** | `read_memory` image values |
| `RET 4` both paths | **High** | epilogues |
| Decompiler MoveTo this wrong | **High** | machine supersedes |
| OnHeartBeat = vtbl+0x0c | **High** | DATA + TryFire |
| RTTI class / ToMouse share | **High** | parent dual + same pointer |
| No direct code callers | **High** | callers empty |
| Product English status=1 | **Open** | not 0/2/0x10 |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ machine (decompile CF with noted gap)

| Stage | Match |
|---|---|
| Null entity → out=1 | **Yes** |
| MoveTo with allowReverse=1 | **Yes** |
| Fail → Stop | **Yes** |
| Entity path → out=0 | **Yes** |
| MoveTo this = entity@+0x24 | **Yes** (clean/machine; **not** raw decompile bind) |
| No invent thr0/HB1 in this body | **Yes** (axes only via MoveTo) |

### 4.1 Dispatch chain (evidence only)

```text
CVOGHBBase_TryFire (0x005082c0)
  └─ call [vtbl+0x0c] → CVOGHBMoveVehicle_OnHeartBeat (this)
       ├─ MoveToTarget3DPoint (entity)
       └─ fail → CVOGHBBase_Stop → OnEnd (0x00636ba0) SetSteer0+Push
```

### 4.2 Decompiler correction (fidelity note)

Raw 2026-07-23 decompile shows:

```c
FUN_004fc650(*(this+0x2c), *(this+0x30), *(this+0x34), 1);
FUN_005081d0(); // no this
```

Machine proves entity remains in ECX and Stop reloads HB into ECX. Clean implements machine truth. Dual does **not** treat decompiler arg bind as sealed.

---

## 5. Gaps (honest)

1. Runtime / CE under live MoveTo fail → Stop → OnEnd.
2. Product English for out-status **1**.
3. Ctor `00636bd0` / dtor `00636d10` residual (not OWN).
4. Who writes entity aim point before fire.
5. PDB method symbol beyond RTTI class + OnHeartBeat slot convention.

---

## 6. Verdict

**accept-with-gaps** — fidelity of CF, ABI, vtbl OnHeartBeat role, entity bind, corrected MoveTo thiscall, Stop-on-fail, and status outs is sealed. Gaps are runtime, status-1 English, and residual class duals only; not CF contradictions.

Path A does **not** claim runtime Confirmed. Terminal: **false**.
