# Review B (skeptical / adversarial): `aa_00756be0` gfxUIWindow_DetachParent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00756be0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-121) |
| **Counterpart** | `reviews/A_aa_00756be0_gfxUIWindow_DetachParent_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / stack `this` | **Falsified** — `MOV ESI,ECX` at entry; dualed sites set **ECX**=parent before CALL |
| 2 | thiscall on **child only** (no parent formal) | **Falsified** — dualed `007917c0`: `MOV ECX,EBP` (dialog) + `PUSH ESI` (child); body reads parent `+0x94`/`+0x98` |
| 3 | bare `RET` / no stack cleanup | **Falsified** — both exits `RET 0x4` (`C2 04 00`) |
| 4 | Frees child or parent | **Falsified** — sole callee is `memmove` IAT; no `operator_delete` / vtbl dtor |
| 5 | Walks / destroys all children | **Falsified** — single linear find + one-slot erase; returns after first match |
| 6 | `+0x88` is a refcount / flag not parent link | **Falsified** — dualed dtor gates on `+0x88` then uses it as **ECX parent**; this body zeros it after erase |
| 7 | Return void / ignore status | **Falsified** — `XOR EAX,EAX` vs `OR EAX,-1`; site `005767a4` tests EAX (`TEST EAX,EAX; JL`) |
| 8 | Product demangle sealed without `_Inferred` | **Fails** — no RTTI/string on leaf; name from dualed gfxUIWindow family + semantics |
| 9 | Scaffold `Named_CalleeOf_*` is product name | **Falsified** — xref-seed only; retired |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX=parent, stack=child, RET 4, EAX status | **High** | Wrong ABI / stack smash |
| Vector `+0x94`/`+0x98`, clear `child+0x88` | **High** | Corrupt child list / parent link |
| memmove compact + end-4 | **High** | Leak slots / double entries |
| Role = detach one child from parent list | **High** | Misport lifecycle |
| Class family gfxUIWindow / dialog share layout | **High** (dualed parents) | Naming only if wrong |
| Exact product method English | **Open** | Naming only |
| Attach peer `00756c50` dual | **Open** | Residual, not this VA |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

```text
// Dualed complete-dtor site (assembly authority @ 0x00759f3a):
//   MOV ECX, [ESI+0x88]     ; parent from child back-link
//   CMP ECX, EBX / JZ skip
//   PUSH ESI                ; child = dying window
//   CALL 0x00756be0
// Matches: ECX=parent, stack=child; child leaves parent's vector before dtor continues
//          to assert "Window deleted with children still attached!" on residual kids.
//
// Dualed dialog teardown site (assembly authority @ 0x007918a5):
//   PUSH ESI; MOV ECX,EBP; CALL 0x00756be0
// Matches: parent=dialog, child=hash entry value; B review of 007917c0 already
//          falsified "thiscall on child only" for this helper.
//
// Body bytes:
//   begin/end loads, linear CMP [EAX],EDI, memmove IAT, end-=4, [EDI+0x88]=0,
//   dual RET 4 — all recovered without disassemble_bytes.
```

A ≡ B on live decompile + full disasm + entry/exit hex + dualed assembly_context.

---

## 4. Surviving contract for AutoCore

```text
// Port as gfxUIWindow parent-list detach leaf (not dtor, not free):
// - ECX = parent; stack = child*; RET 4
// - vector begin@+0x94 end@+0x98 (pointer elements)
// - find child*; memmove compact; end -= 4; child+0x88 = 0
// - return 0 / 0xffffffff
// Do not free child/parent; do not walk remaining children;
// do not invent product demangle; keep _Inferred;
// pair with dualed CompleteDtor 00759de0 and TeardownChildHash 007917c0;
// residual attach peer 00756c50 not dualled here.
```

---

## 5. Verdict

Adversarial pass confirms A's ABI, offset map, memmove erase, dualed call-site parent/child roles, and rejects free/walk/child-thiscall/bare-RET overclaims. Residual product demangle + attach-peer dual → **accept-with-gaps**.
