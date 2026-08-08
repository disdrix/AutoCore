# Review B (skeptical / adversarial): `aa_00416830` Class_00a733ec_Factory_WithFreeCallback_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416830` |
| **VA** | `0x00416830` |
| **Canonical name** | `Class_00a733ec_Factory_WithFreeCallback_Inferred` |
| **Review date** | `2026-08-05` (WQ9K-H dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00416830_Class_00a733ec_Factory_WithFreeCallback_Inferred.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + `disassemble_function` + bulk xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Thiscall ECX=this factory method | **Falsified** — stack arg + `RET 4`; no ECX this |
| 2 | Size other than 0x14 | **Falsified** — `PUSH 0x14` before new |
| 3 | Always non-null | **Falsified** — null-new path zeros EAX |
| 4 | Free callback is null | **Falsified** — writes `0x00573240`; twin `004168c0` is the null path |
| 5 | Free callback is a full product method with many fields | **Falsified** — 15 B thunk: if ctx then `vtbl[0](1)` |
| 6 | Class is literally `"UNI_BUTTONS"` | **Fails** — adjacent UTF-16 after single-slot vtbl; no RTTI seal (same as WQ9J-E) |
| 7 | Same VA as scalar dtor | **Falsified** — factory `00416830` vs dtor `00416f00` |
| 8 | Has direct CALL graph | **Fails** — 0 CALL xrefs (reachability open, body still sealed) |
| 9 | Runtime Confirmed | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
PUSH -1 / PUSH SEH / FS:[0] install
PUSH 0x14 / CALL operator_new / ADD ESP,4
TEST EAX / JZ null
MOV EDX, [ESP+context]
MOV [EAX], 0x00a733ec
MOV [EAX+4], EDX
MOV [EAX+0xc], 0
MOV [EAX+8], 0
MOV [EAX+0x10], 0x00573240
// null: XOR EAX,EAX
FS:[0] restore / ADD ESP,0x10 / RET 4
```

Free thunk @ `0x00573240`:

```text
MOV ECX, [ESP+4]
TEST ECX, ECX
JZ ret
MOV EAX, [ECX]
PUSH 1
CALL [EAX]      // scalar dtor flags=1
RET
```

A ≡ B on body hex + vtbl dword + free-cb bytes.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size / field init | **High** | Wrong object layout |
| RET 4 stdcall | **High** | Stack imbalance |
| Free cb = scalar-delete context | **High** | Leak / wrong teardown |
| Vtbl → dualed dtor | **High** | Wrong type family |
| Call-site reachability | **Open** | Dead-code risk only |
| Product English | **Open** | Naming |

---

## 4. Surviving contract

```text
Class_00a733ec_Factory_WithFreeCallback_Inferred:
  stack context; RET 4
  p = new(0x14) or null
  if p: vtbl=00a733ec; +4=context; +8=+0xc=0; +0x10=LAB_00573240
  return p
// Distinct from null-callback twin 004168c0 and from scalar dtor 00416f00.
```

---

## 5. Verdict

Adversarial pass confirms A's factory CF/ABI/layout/free-cb facts. Rejects thiscall, non-0x14 size, UNI_BUTTONS English seal, and conflation with dtor/twin. Residual call-graph + product name → **accept-with-gaps**.
