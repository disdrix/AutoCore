# Annotated low-level: Object_ResolveCoidVtbl1e8_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004bb1c0` |
| VA | `0x004bb1c0`–`0x004bb1e9` |
| Ghidra name | `FUN_004bb1c0` |
| Proposed name | `Object_ResolveCoidVtbl1e8_Inferred` |
| System | object-resolve / TFID (cross-cutting client) |
| Date | 2026-07-29 (dual A/B seal W18-T; scaffold 2026-07-23) |

---

## Machine-level notes

- **Decompile ≡ body bytes** (`read_memory` 2026-07-29). No `disassemble_bytes`.
- **ABI trap:** Ghidra shows plain three-arg stdcall-looking signature with no `this`. Image is **`RET 0xC`** + **ECX passthrough** into `CVOGReaction_ResolveObjectTarget` — same class as `Object_ResolveFromTFID` / `Object_ResolveTfIdVtbl1d4_Inferred`. Callers load resolve ctx (often `MOV ECX,[host+0xe4e8]`) immediately before `CALL`.
- **Args (stack, free — not a blob\*):** `param_1` = bGlobal (often `0`), `param_2` = coidLo, `param_3` = coidHi. Push order to Resolve: coidHi, coidLo, bGlobal (decompiler still shows Resolve(param_1,param_2,param_3) after convention mapping).
- After resolve: if non-null, **thiscall** `obj->vtbl[+0x1e8]()` and return its result; else return `0`.
- **Not** blob-form `004bb010` (`+0x1d4`); **not** `+0x1d8` / `+0x1dc`; **not** resolve-only `004bb950`.

## Control flow (sealed)

```
// ECX = resolve ctx (caller-supplied; body does not load it)
// stack: bGlobal, coidLo, coidHi; RET 0xC
push coidHi
push coidLo
push bGlobal
obj = CVOGReaction_ResolveObjectTarget(ECX, bGlobal, coidLo, coidHi)
if obj == 0: return 0
return obj->vtbl[0x1e8]()      // ECX = obj
```

## Pseudocode (annotated)

```c
// __thiscall-class: ECX = resolve context; stack bGlobal, coidLo, coidHi; RET 0xC
void *Object_ResolveCoidVtbl1e8_Inferred(
    void *ctx /*ECX*/,
    unsigned bGlobal,
    unsigned coidLo,
    unsigned coidHi)
{
  int *obj = (int *)CVOGReaction_ResolveObjectTarget(
      /*ECX=ctx*/ bGlobal, coidLo, coidHi);
  if (obj != 0)
    return (**(code **)(*obj + 0x1e8))();  // thiscall ECX=obj
  return 0;
}
```

## Callers (role)

| Caller | Use |
|---|---|
| `CVOGSectorMap_DoPlayerOnLoadTrigger` `0x004cdcc0` | Resolve `m_coidPerPlayerLoadTrigger` (`+0xe7e0/+0xe7e4`), bGlobal=0; if non-null fire nested `vtbl+0x114` |
| `CVOGSectorMap_DoCreatorLoadTrigger` `0x004cdd20` | Same pattern for `m_coidCreatorLoadTrigger` (`+0xe7e8/+0xe7ec`) once per map (`+0x74`) |
| `Client_UpdateNpcInteractIcons` `0x0091b8d0` | NPC interact icon path |
| `FUN_004d9b50` (`CVOGSectorMap_RemoveCharacter_Inferred`) | Character-remove related resolve |
| `FUN_004cdc80`, `FUN_004dbef0`, `FUN_004dd940`, `FUN_005aca60`, `FUN_005accf0` | Additional sector/map resolve sites |

## Open questions

1. Product / PDB name of `vtbl+0x1e8` (what interface the virtual returns).
2. Whether return is always identity-equal to resolved `obj` or an unwrap/host pointer.
3. Exhaustive ECX provenance per caller (DoPlayerOnLoad sealed as `host+0xe4e8`).
4. Runtime / bit-exact / image diff not run.
