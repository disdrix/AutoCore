# Review B (skeptical / adversarial): `aa_004168c0` Class_00a733ec_Factory_NullFreeCallback_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004168c0` |
| **VA** | `0x004168c0` |
| **Canonical name** | `Class_00a733ec_Factory_NullFreeCallback_Inferred` |
| **Review date** | `2026-08-05` (WQ9K-I dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004168c0_Class_00a733ec_Factory_NullFreeCallback_Inferred.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + analyze/xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Thiscall ECX=this factory | **Falsified** — stack arg + **`RET 4`**; no ECX this |
| 2 | Installs free callback like twin | **Falsified** — bytes write **0** at `+0x10` (`89 48 10` with ECX=0) |
| 3 | Same binary as `00416830` | **Falsified** — sole diff is `+0x10` target (`LAB_00573240` vs 0) |
| 4 | Size not 0x14 / freelist recycle | **Falsified** — `PUSH 0x14` + `operator_new` |
| 5 | Always non-null return | **Falsified** — OOM path `XOR EAX,EAX` |
| 6 | Class is `"UNI_BUTTONS"` | **Fails** — adjacent .rdata after vtbl; no RTTI seal |
| 7 | Strong CALL graph | **Fails** — 0 xrefs (gap, not falsifier of body) |
| 8 | Runtime Confirmed | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
// SEH setup LAB_009ab4eb
PUSH 0x14
CALL operator_new
ADD ESP,4
TEST EAX,ECX(=0)
JZ null_path
MOV EDX, [stack context]
MOV dword [EAX], 0x00a733ec     // vtbl
MOV [EAX+4], EDX               // context
MOV [EAX+0xC], ECX             // 0
MOV [EAX+8], ECX               // 0
MOV [EAX+0x10], ECX            // 0 free_cb  ← twin would write LAB_00573240
JMP epilog
null_path:
XOR EAX,EAX
epilog:
// restore FS
ADD ESP,0x10
RET 4
```

A ≡ B on live decompile + body hex + twin diff.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Factory CF + size 0x14 | **High** | wrong alloc |
| Null free-cb | **High** | wrong teardown path |
| RET 4 / stack arg | **High** | stack imbalance |
| Product English | **Open** | naming only |
| Callers | **Open** | missing host |

---

## 4. Surviving contract

```text
Class_00a733ec_Factory_NullFreeCallback_Inferred:
  stack context; RET 4
  new(0x14) or null
  vtbl=PTR_FUN_00a733ec; +4=context; +8=+0xc=0; +0x10=null
  return object*
```

---

## 5. Open questions

1. Who calls this factory (pointer table / undualed parent)?
2. Product demangle.
3. Runtime / differential.
