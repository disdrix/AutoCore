# Review B (skeptical / adversarial): `aa_00423be0` AssManager_ResolverA_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423be0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-G) |
| **Counterpart** | `reviews/A_aa_00423be0_AssManager_ResolverA_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — `MOV ESI,[ESP+0x14]`; `RET 4` stack formal |
| 2 | Decompiler `param_1+0xc` is byte offset +0x0c | **Falsified** — dword index → **+0x30** CS; matches `LEA EDI,[ESI+0x30]` |
| 3 | Ready flag at dword +0x12 is +0x12 | **Falsified** — dword ×4 → **+0x48** |
| 4 | Complete dtor / free this | **Falsified** — no `operator_delete`; returns this (placement ctor) |
| 5 | Multiple unrelated roles | **Falsified** — sole xref from AssManager init A path |
| 6 | Scaffold `Named_CalleeOf_*` is product | **Rejected** — parent-seed alias only |
| 7 | Name claims PDB English | **Careful** — `_Inferred` structural only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong calling convention in port |
| Layout +0 / +4 / +8 / +0x30 / +0x48 | **High** | CS/flag misaligned |
| Size 0x4c from caller | **High** | Alloc undersize |
| Nested FUN_00423cf0 body | **Med** | Member residual |
| Product class name | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// AssManager_InitPrecompileAndResolvers flag bit0:
push 0x4c; call operator_new
push eax; call FUN_00423be0   // @ 0x007b776c
mov [ebp+8], eax              // self->resolverA
// then find/PushBackLocked on host+0x58
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23. Full 86 B hex seals offsets.

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
AssResolverA* ctor(AssResolverA* self) {
  self->pad04 = 0;
  self->vtbl = PTR_FUN_00a95acc;
  NestedMember_Ctor(self+0x08);       // FUN_00423cf0
  InitializeCriticalSection(self+0x30);
  *(u8*)(self+0x48) = 1;
  return self;
}
// Alloc 0x4c. Pair with AssManager_ReleaseOwnedResolvers for +0x08 slot.
// Do not invent product English for 00a95acc.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/CF/caller role. Residual nested member + product plate → **accept-with-gaps**.
