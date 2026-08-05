# Review B (skeptical / adversarial): `aa_0094bed0` Object_009d33c4_FactoryRegisterListed_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094bed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-K dual B) |
| **Counterpart** | `reviews/A_aa_0094bed0_Object_009d33c4_FactoryRegisterListed_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_0094bed0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Signature is `int* FUN…(void)` | **Falsified** — EDI host + 2 stack dwords + `ret 8` |
| 2 | `FUN_00512160` args are SEH locals | **Falsified** — bytes load `[esp+0x18]/[esp+0x1c]` stack formals |
| 3 | ExceptionList restore uses `DAT_00af30f4` / host field | **Falsified** — SEH frame stack restore |
| 4 | Multiple factories for this path | **Falsified** — sole CALL `FUN_008119c0` |
| 5 | Alloc size unrelated to `009d33c4` | **Falsified** — ctor is W29-H `Object_009d33c4_Ctor`; size 0x210 covers derived region to +0x200 |
| 6 | Register fail returns non-null | **Falsified** — hr&lt;0 → vtbl[0](1) → NULL |
| 7 | Product name confirmed | **Overstated** — structural `_Inferred` from vtbl/ctor family only |
| 8 | Null `operator_new` returns NULL safely | **Overstated** — no early return; subsequent `*obj` is undefined |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes / ABI / ret 8 / EDI | **High** | Wrong port ABI |
| Callee graph | **High** | Wrong factory stages |
| COID stamp + register fail | **High** | Leaks / wrong identity |
| Product English / virtual meaning | **Medium–Low** | Naming only / port comments |
| OOM path | **Open** | Crash-on-OOM parity |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw decompile: void formals, unaff_EDI, SetCoidIdentity(SEH locals), ExceptionList mixups
bytes: SEH + new(0x210) + ctor + vtbl+8 + SetCoid(stack) + vtbl+0x218 + RegisterListed + ret 8
caller 00811a0f: push [esi+0xc],[esi+8]; edi=ebx; call
```

Clean **must**:
- take EDI host + two COID stack args with `ret 8`,
- not invent null-new early return unless image adds one,
- call RegisterListed on `*(host+0xd34)`,
- scalar-delete on hr&lt;0 only.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_0094bed0 — Object_009d33c4_FactoryRegisterListed_Inferred
// EDI=host, stack (coidLo, coidHi), ret 8, returns object* or null
unsafe void* Factory(void* host, uint coidLo, uint coidHi)
{
    void* obj = Alloc(0x210);
    if (obj != null) obj = Object_009d33c4_Ctor(obj);
    // virtuals + SetCoid + RegisterListed as sealed; fail → scalar delete → null
    return obj;
}
```

---

## 5. Verdict

Adversarial pass **confirms** A on bytes/ABI/CF; product English + OOM + virtual semantics remain open → **accept-with-gaps**.
