# Annotated low-level: CVOGReaction_ResolveObjectTarget

| Field | Value |
|---|---|
| Stable ID | `aa_004bae70` |
| VA | `0x004bae70` |
| System | object-resolve / reaction |
| Date | 2026-07-23 scaffold; **annotated strengthen 2026-07-29** |

---

## Machine-level notes

- Source: raw capture for `aa_004bae70` + live `read_memory` body (2026-07-29).
- **Prefer assembly when decompiler conflicts** — confirmed: Ghidra drops table `mov ecx,[ecx+4|8]`.
- Calling convention: `__thiscall` ECX=ctx; stack `bGlobal, coidLo, coidHi`; **`ret 0x0c`**.
- Both CALL sites target `FUN_004e3260` (`0x004e3260`) with ECX preloaded to a hash table.
- Side effects: **none** (no stores).

## Image control flow (authoritative)

```
004bae70  mov eax, [esp+8]          ; coidLo
          mov edx, [esp+0xc]        ; coidHi
          push esi
          mov esi, eax
          and esi, edx
          cmp esi, -1
          pop esi
          jz  ret0                  ; both halves 0xFFFFFFFF
          cmp byte ptr [esp+4], 0   ; bGlobal
          jz  local_path
          ; --- bGlobal != 0 (global domain) ---
          cmp byte ptr [ecx+0xc], 0
          jz  ret0
          mov ecx, [ecx+4]          ; table = ctx+0x4
          push edx
          push eax
          call FUN_004e3260
          ret 0x0c
local_path:
          cmp byte ptr [ecx+0xd], 0
          jz  ret0
          mov ecx, [ecx+8]          ; table = ctx+0x8
          push edx
          push eax
          call FUN_004e3260
          ret 0x0c
ret0:
          xor eax, eax
          ret 0x0c
```

## Corrected pseudocode (post-strengthen)

```c
void * __thiscall
CVOGReaction_ResolveObjectTarget(void *ctx, unsigned char bGlobal,
                                 unsigned int coidLo, unsigned int coidHi)
{
  if ((coidLo & coidHi) == 0xFFFFFFFFu)
    return 0;

  if (bGlobal != 0) {
    if (*(char *)((char *)ctx + 0xc) == 0)
      return 0;
    return FUN_004e3260(*(void **)((char *)ctx + 4), coidLo, coidHi);
  }

  if (*(char *)((char *)ctx + 0xd) == 0)
    return 0;
  return FUN_004e3260(*(void **)((char *)ctx + 8), coidLo, coidHi);
}
```

## Scaffold decompiler (incomplete — do not port)

Raw Ghidra body treated both arms as `FUN_004e3260(coidLo, coidHi)` without reloading ECX from `ctx+4` / `ctx+8`. Flag/branch shape was correct; **table selection was not**.

## Ctx offsets (this unit)

| Off | Use | Confidence |
|---|---|---|
| `+0x4` | pointer → hash table (bGlobal≠0 path) | **High** |
| `+0x8` | pointer → hash table (bGlobal==0 path) | **High** |
| `+0xc` | enable flag (char) for global path | **High** as gate; English open |
| `+0xd` | enable flag (char) for local path | **High** as gate; English open |

## Callee (not owned)

`FUN_004e3260`: thiscall table; `bucket = coidLo & table[+0x8]`; buckets at `table[+0x10]`; walk `FUN_004e23d0`; return `node[+0xc]`.

## Open questions

- Product names for tables / `FUN_004e3260`
- Who writes flags `+0xc` / `+0xd`
- Exact C++ type of `ctx`
