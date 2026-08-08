# Annotated low-level: Host_DualCNDHash_TraverseNextObject_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004bae00` |
| VA | `0x004bae00`–`0x004bae63` inclusive (**100 B** / `0x64`) |
| Ghidra name | `FUN_004bae00` |
| Preferred name | `Host_DualCNDHash_TraverseNextObject_Inferred` |
| System | interaction-activation (pick-list / SelectBestPick residual) |
| Date | `2026-08-05` (MEGA-011 OWN dual; supersedes 2026-07-23 scaffold) |

## Machine-level notes

- Source: raw capture + live Ghidra re-verify (MEGA-011).
- Prefer assembly when decompiler elides ECX into callees.
- Decompiler shows `__thiscall` with `param_1` = host (ECX) — correct.
- Decompiler reorders flag branches vs assembly (asm tests non-zero first); **semantics identical**.
- Callee ECX is **restored** from `host+4` / `host+8` before each CALL (decompiler drops those MOVs).
- Unlock is **inline** `MOV byte [hash+0x1d], 0` — not `List_TraversalUnlock` (CS family +0x28).

## Signature (sealed)

```c
// ECX = dual-list host*
// stack0 = char listSelect  (0 → list B @ +0x8; ≠0 → list A @ +0x4)
// stack1 = int* cursor      (node* walk state; 0 = start at head)
// EAX = object* payload (node+0xc) or NULL
// cleanup: RET 8
void* __thiscall Host_DualCNDHash_TraverseNextObject_Inferred(
    void* host,
    char listSelect,
    int* cursor);
```

## Host layout

| Off | Role | Conf |
|----:|------|------|
| `+0x4` | CNDHash* **list A** (`listSelect != 0`) | **High** |
| `+0x8` | CNDHash* **list B** (`listSelect == 0`) | **High** |
| `+0xc` | enable byte for list A | **High** |
| `+0xd` | enable byte for list B | **High** |

## Pseudocode (annotated; CF ≡ raw ≡ live)

```c
void* __thiscall Host_DualCNDHash_TraverseNextObject_Inferred(
    void* host /* ECX */,
    char listSelect,
    int* cursor)
{
  void* result;

  if (listSelect == 0) {
    // list B: enable @ host+0xd, hash @ host+0x8
    if (*(char*)((char*)host + 0xd) != 0 && *(int*)((char*)host + 8) != 0) {
      CNDHash_TraversalLock_Set_Inferred(*(int*)((char*)host + 8));   // ECX=hash
      result = CNDHash_TraverseToNext_Payload0C(*(int*)((char*)host + 8), cursor);
      *(uint8_t*)(*(int*)((char*)host + 8) + 0x1d) = 0;              // unlock
      return result;
    }
  }
  else if (*(char*)((char*)host + 0xc) != 0 && *(int*)((char*)host + 4) != 0) {
    // list A: enable @ host+0xc, hash @ host+0x4
    CNDHash_TraversalLock_Set_Inferred(*(int*)((char*)host + 4));
    result = CNDHash_TraverseToNext_Payload0C(*(int*)((char*)host + 4), cursor);
    *(uint8_t*)(*(int*)((char*)host + 4) + 0x1d) = 0;
    return result;
  }
  return 0;
}
```

## Callees

| VA | Name / role |
|---|---|
| `0x00402c40` | `CNDHash_TraversalLock_Set_Inferred` (dualed MEGA-110) — soft set `hash+0x1d=1` |
| `0x004bc530` | CNDHash TraverseToNext residual (MEGA-029) — string `"HashError:TraverseToNext, not locked for traversal"`; returns `*(node+0xc)` |

## Callers (role)

Primary consumer dualed: `Client_Interact_SelectBestPickTarget` (`0x00490070`) — two passes flag **0 then 1** over `Client+0xBC` host. Shared world-object enumerator across flush / mission / sector host paths (13 callers, 28 call sites).

## Open questions

- Product RTTI English for dual-list host class (offsets only sealed).
- Whether list A/B map to product names (e.g. static vs dynamic object buckets) — **Tentative**.
- Full dual of `FUN_004bc530` (MEGA-029 OWN residual).
- Runtime Confirmed open (no Launcher).
