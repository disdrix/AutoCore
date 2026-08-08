# Review B (skeptical / adversarial): `aa_008e5990` UI_CraftHost_BindResolvedObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5990` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-032) |
| **Counterpart** | `reviews/A_aa_008e5990_UI_CraftHost_BindResolvedObject_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / stdcall with host on stack | **Falsified** — callers `MOV ECX,host; PUSH object; CALL`; prolog `MOV ESI,ECX` |
| 2 | `RET 0` / more than one stack arg | **Falsified** — exit `C2 04 00` (**RET 4**); single stack object* |
| 3 | Is the TFID resolver | **Falsified** — parent `008e5ce0` resolves TFID; this unit only binds resolved ptr / null |
| 4 | Always rebuilds chrome even when attach root present with old chrome | **Partial** — old chrome deleted **only if** `+0x7d0 != 0 && +0x520 == 0`; if attach root set, old chrome pointer is **overwritten** by new alloc without that delete path (bind path always `operator_new` into `+0x7d0`) |
| 5 | Decompiler zero-arg `FUN_00599dd0()` is full ABI | **Decompiler fail** — assembly sets `ECX = [[obj+0xa8]+0x3c]` before CALL; annotated/clean correct |
| 6 | Tail refresh always runs | **Falsified** — `599dd0==0` jumps to SEH epilogue, **skipping** `008e55e0` / `008e47d0` |
| 7 | Mission-UI-only (Named_CalleeOf RefreshOpen scaffold) | **Falsified** — dualed parent is craft-host TFID bind; inventory-transfer system; scaffold retired |
| 8 | Product name sealed from RTTI | **Fails** — no RTTI string in unit → `_Inferred` required |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 10 | Slot count other than 5 | **Falsified** — `MOV EBX,5` / recipe loop `CMP EDI,5` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall host + stack object + RET 4 | **High** | Wrong ABI / stack smash |
| `+0x7cc` bound object store | **High** | Selection state wrong |
| 5-slot clear @ `+0x568` / `+0x590` | **High** | Stale materials in UI |
| Null hide vs non-null show/bind | **High** | Wrong panel state |
| `.geo` append from `DAT_00a28904` | **High** | Wrong mesh/name key |
| Chrome size `0x14c` + ctor `00764030` | **High** | Leak / bad vtbl |
| 599dd0 early-out skips refresh | **High** | Port would over-refresh |
| Helper English (`5120`/`5220`/…) | **Med** (not OWN) | Recipe fill edge cases |
| Craft host product class name | **Med** (parent dual) | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

```text
// Parent TFID bind (dualed) — clear path:
//   PUSH 0
//   MOV ECX, host
//   CALL 0x008e5990          @ 008e5cf9
// Parent TFID bind — success path:
//   PUSH obj
//   MOV ECX, host
//   CALL 0x008e5990          @ 008e5de8
// Other parents same ABI:
//   008e80e5 (FUN_008e6b50), 0093a3aa / 0093a3c5 (FUN_0093a330)
// Exit:
//   ADD ESP,0x198 ; RET 4
// Pad CC then Client_UI_CraftHost_BindObjectByTfid_Inferred @ 008e5ce0
// DAT_00a28904: 2e 67 65 6f 00  => ".geo"
```

A ≡ B on live decompile + full disasm + xref assembly_context + string bytes.

---

## 4. Surviving contract for AutoCore

```text
// Port as craft-host bind of resolved object*:
// - inputs: host (ECX this), object* or null (stack), RET 4
// - host+0x7cc = object (even when null)
// - clear 5 material slots; null → hide selection; non-null → show + name chrome ".geo"
// - if recipe query FUN_00599dd0 fails: return WITHOUT host refresh tail
// - do NOT implement TFID resolution here (parent 008e5ce0)
// - do NOT treat as mission-dialog-only despite old Named_CalleeOf scaffold
// - do not invent RTTI product class name
```

---

## 5. Verdict

Adversarial pass confirms A's ABI, offsets, null/bind split, `.geo` chrome, five-slot clear, 599dd0 early-out, and call-site patterns. Rejects cdecl / TFID-resolver / always-refresh / mission-only overclaims. Residual product English + helper duals → **accept-with-gaps**.
