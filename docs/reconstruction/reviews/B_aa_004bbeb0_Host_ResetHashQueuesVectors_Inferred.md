# Review B (skeptical / adversarial): `aa_004bbeb0` Host_ResetHashQueuesVectors_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbeb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-N) |
| **Counterpart** | `reviews/A_aa_004bbeb0_Host_ResetHashQueuesVectors_Inferred.md` |
| **Scratch** | `tmp/a_004bbeb0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler ECX is correct as bare calls | **Falsified** — bytes load ECX from `+0x18/+0x1c/+0x20/+0x24` or LEA `+0x48/+0x28/+0x38` |
| 2 | Hash is embedded at +0x18 | **Falsified** — `MOV ECX,[ESI+0x18]` pointer load, not LEA |
| 3 | Second vtbl is jumptable | **Falsified** — `FF 62 04` after `POP ESI` is tail JMP |
| 4 | Vectors grow (non-zero size) | **Falsified** — both stack args are 0 |
| 5 | This is a dtor / frees `this` | **Falsified** — no `operator_delete(this)`; recreate/drain/clear only |
| 6 | cdecl / no this | **Falsified** — `MOV ESI,ECX` |
| 7 | Scaffold Server_needs_an_update plate is product | **Falsified** — chain name only; no string evidence in body |
| 8 | Always calls both ifaces | **Falsified** — gated by `+0x0c` / `+0x0d` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Reset vs dtor | **High** | Wrong lifetime |
| Hash ptr + log2=5 | **High** | Wrong table size / crash |
| Three queue drains | **High** | Leak / missed clear |
| Vector clear offsets | **High** | Corrupt wrong fields |
| Tail vs call on +0x0d | **High** | Stack imbalance if ported as call after pop |
| Product host class | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// W30-G: sole consumer of CNDHash_Recreate_009cb450 is this unit @ 004bbeb8, always bits=5
// Callers FUN_004d98f0 / FUN_00943b80 invoke after dual FUN_004bae00 object sweeps
// FUN_004bc580: EnterCS, drain list+0x1c via scalar-delete, clear heads — not owned here
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 stage list. Full 104 B hex seals ECX + tail.

---

## 4. Surviving contract for AutoCore

```
// Port as host RESET (not dtor):
void Host_ResetHashQueuesVectors(Host* h) {
  CNDHash_Recreate_009cb450(h->pHash18, /*log2*/5);  // do not swap Free/Alloc twins
  drain_locked_list(h->q1c); drain(h->q20); drain(h->q24);  // FUN_004bc580
  vec_resize_dword(h->v48, 0); vec_resize(h->v28,0); vec_resize(h->v38,0);
  if (h->flag0c) h->iface04->vtbl[1]();
  if (h->flag0d) return h->iface08->vtbl[1](); // tail
}
// Preserve call order. Do not invent product class plate.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/ECX/tail. Product English + nested drain dual residual → **accept-with-gaps**.
