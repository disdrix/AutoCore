# Review B (skeptical / adversarial): `aa_00442c80` HostAux14_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00442c80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-S) |
| **Counterpart** | `reviews/A_aa_00442c80_HostAux14_Ctor_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX thiscall entry | **Falsified** — bytes load self from stack (`[esp+0x10]` after SEH); never uses ECX as object |
| 2 | Decompiler `void` means no return value | **Falsified** — EAX holds self through body; sole caller `mov [esi+8], eax` depends on return |
| 3 | Zeros all five dwords of 0x14 object | **Falsified** — only indices 0 (vtbl) and 2..4; **+4 untouched** |
| 4 | Multiple callers / shared utility | **Falsified** — single xref from `FUN_00756320` @ `0x00756375` |
| 5 | Scaffold VOG_DEBUG_STOP product plate | **Reject** — no such string in body; parent-seed noise |
| 6 | Size larger than 0x14 | **Falsified** — EnsureAuxPtrs `operator_new(0x14)` + field map ends at +0x10 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack self* + RET 4 | **High** | Wrong calling convention / stack corrupt |
| EAX returns self | **High** | Null/garbage `host+8` |
| +4 not written | **High** | Overwrite reserved field |
| Product class English | **Low** | Naming only |
| Vtbl method semantics | **Open** | Wrong virtual dispatch later |

---

## 3. Cross-check against raw + body + peers

```
// HostBase_EnsureAuxPtrs (00756320):
//   raw = operator_new(0x14)
//   if raw: [host+8] = FUN_00442c80(raw)  // push; call; use EAX
// FUN_007560d0 zeros host+4/+8 before ensure
// Phase enables re-call ensure; this ctor only on first success path
```

Live decompile ≡ raw CF; full 58 B hex seals SEH, vtbl imm `00a9f49c`, three zero stores, `RET 4`.

---

## 4. Surviving contract for AutoCore

```
// Port as small host-aux ctor (stack self*, RET 4, returns self):
void* HostAux14_Ctor(void* self) {
  auto* p = (uint32_t*)self;
  p[0] = (uint32_t)&PTR_FUN_00a9f49c; // vtbl
  // p[1] untouched
  p[2] = p[3] = p[4] = 0;
  return self;
}
// Only from EnsureAuxPtrs after new(0x14). Do NOT invent ECX thiscall entry.
// Do NOT invent VOG_DEBUG_STOP plate.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, layout, sole caller, and return-in-EAX. Product English residual only → **accept**.
