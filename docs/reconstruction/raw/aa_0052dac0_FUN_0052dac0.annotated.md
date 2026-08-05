# Annotated low-level: FUN_0052dac0

| Field | Value |
|---|---|
| Stable ID | `aa_0052dac0` |
| VA | `0x0052dac0` |
| System | `missions-progression` |
| Date | `2026-07-29` (seal pass: dual A/B + three-rep + asm) |

## Machine-level notes

- **Authoritative for map base:** assembly uses `lea ecx,[esi+0x508]` before `FUN_00538a40`. Decompiler omits this and passes whole `this` — **do not trust** that part of the decompile.
- **ABI:** `sub esp,0x34` / `push esi` / … / `pop esi` / `add esp,0x34` / **`ret 8`** (three exit clones).
- **Hit path:** `mov eax,[esp+4]` (node*) / `cmp eax,[esi+0x50c]` / jnz → `add eax,0x18` / ret.
- **Miss + flag0:** `cmp byte [esp+0x40],0` / jz → `xor eax,eax` / ret.
- **Miss + flag1:** fill stack payload with `or eax,-1` stores; `lea edx,[esp+8]`; `push edx; push key; mov ecx,esi; call FUN_0052c700`; ret with EAX from callee.
- `FUN_0052c700` ends with `mov eax,[eax]; add eax,0x18; mov [eax+0x28],key` — returns region*, stores key at region+0x28.

## Pseudocode (annotated; map base corrected)

```c
/* WARNING: Type propagation algorithm not settling — map this is this+0x508, not this */

/* __thiscall | ret 8 */
int __thiscall FUN_0052dac0(int this, undefined4 key, char createIfMissing)
{
  int node;
  int local_34[12];   /* [0]=node* out; [1..] payload for insert */
  undefined1 local_4;

  /* asm: ECX = this+0x508 (map), not this */
  FUN_00538a40(/*map*/ this + 0x508, /*out*/ local_34, /*key*/ &key);
  node = local_34[0];

  if (node != *(int *)(this + 0x50c)) {   /* not end sentinel */
    return node + 0x18;                   /* reward / value region */
  }
  if (createIfMissing == '\0') {
    return 0;
  }

  /* 11× dword 0xFFFFFFFF in payload window; trailing byte 0; copy 12 dwords in callee */
  local_34[9]  = 0xffffffff;
  local_34[10] = 0xffffffff;
  local_34[0xb] = 0xffffffff;
  local_34[1]  = 0xffffffff;
  local_34[2]  = 0xffffffff;
  local_34[3]  = 0xffffffff;
  local_34[4]  = 0xffffffff;
  local_34[5]  = 0xffffffff;
  local_34[6]  = 0xffffffff;
  local_34[7]  = 0xffffffff;
  local_34[8]  = 0xffffffff;
  local_4 = 0;

  /* FUN_0052c700 is NOT void — returns node+0x18 */
  return FUN_0052c700(this, key, local_34 + 1);
}
```

## Callers (create flag)

| VA | Caller | flag |
|---|---|---|
| `0x00943a85` | `Client_ShowNpcMissionDialogUI` | 0 (lookup only) |
| `0x004d0912` | `FUN_004d08c0` | 1 |
| `0x004d5d20` | `FUN_004d5c10` | 1 |
| `0x004d5e90` | `FUN_004d5c10` | 1 |
| `0x004d63f6` | `FUN_004d5c10` | 1 |

## Open questions

- Full field map of region at `node+0x18`.
- Product names for map container / insert helper.
