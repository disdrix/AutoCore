# Review A (reconstruction fidelity): `aa_00914c60` Client_SetModeLatch493_ParkDriveOnClear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00914c60` |
| **VA** | `0x00914c60`–`0x00914ce5` inclusive (**134 B** / `0x86`) |
| **Canonical name** | `Client_SetModeLatch493_ParkDriveOnClear_Inferred` (Ghidra `FUN_00914c60`) |
| **Prior scaffold** | `FUN_00914c60` (2026-07-23 partial) |
| **Review date** | `2026-08-05` (OWN-ONLY dual A/B **R11-037** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ entry bytes) |
| **Counterpart** | `reviews/B_aa_00914c60_Client_SetModeLatch493_ParkDriveOnClear_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create/seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` / `analyze_function_complete` / `disassemble_function` / `get_function_callers` / `get_function_xrefs` / `get_function_by_address` / `read_memory` @ entry + body end. Prefer decompile/`read_memory`. Own VA only. No ledgers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Client **virtual thiscall** that sets/clears mode latch `+0x493`:

1. **Clear** (`enable==0`, latch already set): UI/camera cleanup (`FUN_007fb990` with ESI=`&DAT_00d1a840`), park drive via dualed `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` (`0x00914c20`, EAX=this), optional cursor-host notify `vtbl+4(0)` when `DAT_00d1b9a8` query `vtbl+0xd0` is true.
2. **Enable** (`enable!=0`, latch clear, host non-null): optional cursor-host notify `vtbl+4(1)` when query is false.
3. **Always**: zero **f32** at `this+0x538`, then `FUN_007902a0(this, enable)` to apply latch.

**Live decompile (`0x00914c60`, 2026-08-05):**

```c
void __thiscall FUN_00914c60(int param_1,undefined4 param_2)
{
  char cVar1;
  undefined4 uVar2;

  if ((char)param_2 == '\0') {
    if (*(char *)(param_1 + 0x493) == '\0') goto LAB_00914cce;
    FUN_007fb990();
    FUN_00914c20();
    if (DAT_00d1b9a8 == (int *)0x0) goto LAB_00914cce;
    cVar1 = (**(code **)(*DAT_00d1b9a8 + 0xd0))();
    if (cVar1 == '\0') goto LAB_00914cce;
    uVar2 = 0;
  }
  else {
    if ((*(char *)(param_1 + 0x493) != '\0') || (DAT_00d1b9a8 == (int *)0x0)) goto LAB_00914cce;
    cVar1 = (**(code **)(*DAT_00d1b9a8 + 0xd0))();
    if (cVar1 != '\0') goto LAB_00914cce;
    uVar2 = 1;
  }
  (**(code **)(*DAT_00d1b9a8 + 4))(uVar2);
LAB_00914cce:
  *(undefined4 *)(param_1 + 0x538) = 0;   // asm: XORPS+MOVSS f32
  FUN_007902a0(param_2);
  return;
}
```

≡ frozen raw (2026-07-23) CF; ≡ annotated refresh; ≡ clean (named + twin).

**Entry bytes (`read_memory` len 134):**

```text
538b5c240884db578bf9742380bf930400000075598b0da8b9d10085c9744f8b01ff90d000000084c075436a01eb3480bf9304000000743656be40a8d100e8ed6ceeff8bc7e876ffffff8b0da8b9d10085c95e74198b01ff90d000000084c0740d6a008b0da8b9d1008b11ff52040f57c0538bcff30f118738050000e8bfb5e7ff5f5bc20400
```

Relative calls sealed: `@00914c9e`→`007fb990`; `@00914ca5`→`00914c20`; `@00914cdc`→`007902a0`. RET `C2 04 00`.

---

## 2. Inspected artifacts

| Artifact | Path / tool | This pass |
|---|---|---|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00914c60_FUN_00914c60.md` | ≡ live CF |
| Annotated | `docs/reconstruction/raw/aa_00914c60_FUN_00914c60.annotated.md` | refreshed |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_SetModeLatch493_ParkDriveOnClear_Inferred.cpp` | CF match |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00914c60.cpp` | CF match |
| Function records | `functions/aa_00914c60_FUN_00914c60.md` + named | sealed |
| Live decompile | Ghidra `0x00914c60` | **≡ raw** |
| Live disasm | `disassemble_function` | full body |
| Live bytes | `read_memory` 134 B @ entry; pad @ end | seals |
| Live xrefs | `get_function_xrefs` | **1** DATA `@00a2f468` |

**Not performed:** Launcher, runtime golden, package bit-exact, Ghidra product rename, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `00914c60`–`00914ce5` (134 B) | **High** | `get_function_by_address` + `RET 4` + CC pad |
| thiscall ECX + stack enable + `RET 4` | **High** | `MOV EDI,ECX`; `MOV EBX,[ESP+8]`; `C2 04 00` |
| Clear path: fb990 → 14c20 → optional host(0) | **High** | order sealed in disasm |
| Enable path: optional host(1) only | **High** | no Stop / no fb990 |
| Always zero f32 `+0x538` then `007902a0` | **High** | XORPS/MOVSS + CALL |
| Stop leaf ABI EAX=this (`MOV EAX,EDI`) | **High** | site `@00914ca5` |
| ESI imm `&DAT_00d1a840` for fb990 | **High** | `BE 40 A8 D1 00` |
| Sole xref DATA vtable `@00a2f468` | **High** | no direct callers |
| Product English (`+0x493`, `+0x538`, host slots) | **Open** | `_Inferred` |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Branch on enable low byte | **Yes** |
| Latch gate polarity (clear needs set; enable needs clear) | **Yes** |
| Clear-only Stop + UI cleanup | **Yes** |
| Host query polarity inverted clear vs enable | **Yes** |
| Always-tail float zero + latch apply | **Yes** |
| No direct steer/long stores in body | **Yes** |

### 4.1 Contract

```
SetModeLatch493_ParkDriveOnClear(client ECX, enable stack):
  if enable == 0:
    if client.latch_493 == 0: goto tail
    FUN_007fb990(ESI=&DAT_00d1a840)
    StopHbAndZeroLongitudinal(EAX=client)
    if host && host.query(): host.notify(0)
  else:
    if client.latch_493 != 0 || !host: goto tail
    if !host.query(): host.notify(1)
tail:
  client.f32_538 = 0.0f
  FUN_007902a0(client, enable)   // writes latch_493
  ret 4
```

---

## 5. Gaps (accepted)

- Product labels for `+0x493` / `+0x538` / `DAT_00d1b9a8` vtbl methods.
- Class owning vtable slot `@00a2f468`.
- Residual callees `007fb990` / `007902a0` not dualled here (OWN-ONLY).
- Runtime Confirmed / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/RET/xref/byte seals closed; product English + runtime open.
