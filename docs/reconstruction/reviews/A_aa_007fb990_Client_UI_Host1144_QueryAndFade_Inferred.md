# Review A (reconstruction fidelity): `aa_007fb990` Client_UI_Host1144_QueryAndFade_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb990` |
| **VA** | `0x007fb990`–`0x007fb9d3` inclusive (**68 B** / `0x44`) |
| **Canonical name** | `Client_UI_Host1144_QueryAndFade_Inferred` (Ghidra `FUN_007fb990`) |
| **Prior scaffold** | `FUN_007fb990` / `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007fb990` |
| **Review date** | `2026-08-05` (OWN-ONLY dual A/B **R12-007** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ entry bytes) |
| **Counterpart** | `reviews/B_aa_007fb990_Client_UI_Host1144_QueryAndFade_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create/seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` / `analyze_function_complete` / `disassemble_function` / `get_function_callers` / `get_function_xrefs` / `get_function_by_address` / `get_assembly_context` / `read_memory` @ entry + body end. Prefer decompile/`read_memory`. Own VA only. No ledgers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Shared **ESI-host leaf** that, when client UI host slot `+0x1144` holds a live NDUI object, runs a three-gate virtual chain and optionally fades it:

1. Non-null `*(host+0x1144)`.
2. Query `obj->vtbl[+0xd0]()` returns non-zero (AL).
3. State `obj->vtbl[+0xe8]()` returns **not** `-1` (EAX).
4. Then `obj->vtbl[+0xfc](0, 0.1f)` with stack args `PUSH 0.1f; PUSH 0` (thiscall ECX=obj).

Callers (mode-latch clear, skill-target cancel, key match, interact cancel, packet/UI teardown paths) almost always load **`ESI = &DAT_00d1a840`** immediately before the CALL. Slot `+0x1144` is installed by dualed `Client_UI_CreateNDUIDialogs_InstallHost_Inferred` (`0x0093e7e0`) via `operator_new(0x488)` + `FUN_007b5dd0` ctor + post-init `vtbl+0x28` / `vtbl+0xcc`.

**Live decompile (`0x007fb990`, 2026-08-05):**

```c
void FUN_007fb990(void)
{
  char cVar1;
  int iVar2;
  int unaff_ESI;

  if (*(int *)(unaff_ESI + 0x1144) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xd0))();
    if (cVar1 != '\0') {
      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xe8))();
      if (iVar2 != -1) {
        (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xfc))(0,0x3dcccccd);
      }
    }
  }
  return;
}
```

≡ frozen raw (2026-07-23) CF; ≡ annotated refresh; ≡ clean (named + twin).

**Full disasm (`disassemble_function`):**

```text
007fb990  CMP dword ptr [ESI + 0x1144], 0x0
007fb997  JZ  0x007fb9d3
007fb999  MOV ECX, dword ptr [ESI + 0x1144]
007fb99f  MOV EAX, dword ptr [ECX]
007fb9a1  CALL dword ptr [EAX + 0xd0]
007fb9a7  TEST AL, AL
007fb9a9  JZ  0x007fb9d3
007fb9ab  MOV ECX, dword ptr [ESI + 0x1144]
007fb9b1  MOV EDX, dword ptr [ECX]
007fb9b3  CALL dword ptr [EDX + 0xe8]
007fb9b9  CMP EAX, -0x1
007fb9bc  JZ  0x007fb9d3
007fb9be  MOV ECX, dword ptr [ESI + 0x1144]
007fb9c4  MOV EAX, dword ptr [ECX]
007fb9c6  PUSH 0x3dcccccd          ; f32 0.1
007fb9cb  PUSH 0x0
007fb9cd  CALL dword ptr [EAX + 0xfc]
007fb9d3  RET
```

**Entry bytes (`read_memory` len 68 + pad):**

```text
83be4411000000743a8b8e441100008b01ff90d000000084c074288b8e441100008b11ff92e800000083f8ff74158b8e441100008b0168cdcccc3d6a00ff90fc000000c3
```

Pad `CC` from `0x007fb9d4`. Plain `RET` (`C3`) — **no** stack cleanup.

---

## 2. Inspected artifacts

| Artifact | Path / tool | This pass |
|---|---|---|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_007fb990_FUN_007fb990.md` | ≡ live CF |
| Annotated | `docs/reconstruction/raw/aa_007fb990_FUN_007fb990.annotated.md` | refreshed |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_UI_Host1144_QueryAndFade_Inferred.cpp` | CF match |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007fb990.cpp` | CF match |
| Function records | `functions/aa_007fb990_FUN_007fb990.md` + named | sealed |
| Live decompile | Ghidra `0x007fb990` | **≡ raw** |
| Live disasm | `disassemble_function` | full body |
| Live bytes | `read_memory` 68 B @ entry; pad @ end | seals |
| Live xrefs | `get_function_xrefs` | **15** UNCONDITIONAL_CALL |
| Call-site ESI | `get_assembly_context` on all 15 | majority `MOV ESI,0xd1a840` |

**Not performed:** Launcher, runtime golden, package bit-exact, Ghidra product rename, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `007fb990`–`007fb9d3` (68 B) | **High** | `get_function_by_address` + plain RET + CC pad |
| ESI = host convention (not ECX thiscall) | **High** | no `MOV ECX` host; callers load ESI; `unaff_ESI` in decompile |
| Plain `RET` / zero stack args | **High** | `C3`; no `RET n` |
| Triple gate: null / query / state≠-1 | **High** | three JZ to shared RET |
| Fade args `(0, 0.1f)` thiscall on obj | **High** | PUSH order + `0x3dcccccd` = 0.1f |
| Slot install at host `+0x1144` | **High** | CreateNDUIDialogs install plate |
| Shared cancel/cleanup leaf | **High** | 15 call sites across input/mode/skill |
| Product English for dialog class / vtbl slots | **Open** | `_Inferred` |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null-check `+0x1144` | **Yes** |
| Query `vtbl+0xd0` → AL | **Yes** |
| State `vtbl+0xe8` → EAX ≠ -1 | **Yes** |
| Fade `vtbl+0xfc(0, 0.1f)` | **Yes** |
| No other side effects / no callees by name | **Yes** |
| Plain RET | **Yes** |

### 4.1 Contract

```
Host1144_QueryAndFade(ESI = clientUiHost):
  obj = *(host + 0x1144)
  if obj == null: ret
  if !obj->vtbl[+0xd0](): ret          // query
  if obj->vtbl[+0xe8]() == -1: ret     // state/index
  obj->vtbl[+0xfc](0, 0.1f)            // fade / transition
  ret                                  // plain C3
```

---

## 5. Gaps (accepted)

- Product class name for `+0x1144` object (ctor `FUN_007b5dd0`, vtable `PTR_FUN_00a960ac` residual).
- English for vtbl slots `+0xd0` / `+0xe8` / `+0xfc` (query / state / fade inferred from ABI + call patterns only).
- Whether arg0=`0` means “hide”, “cancel mode”, or “fade-to-zero alpha” (not sealed).
- Runtime Confirmed / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/RET/xref/byte/ESI seals closed; product English + runtime open.
