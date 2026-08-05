# Annotated low-level: NDUIWindow_ReloadInterface

| Field | Value |
|---|---|
| Stable ID | `aa_00792980` |
| VA | `0x00792980` – `0x00792a41` |
| System | client UI / NDUI |
| Date | 2026-07-23 scaffold; annotate pass 2026-07-29 dual |

## Machine-level notes

- Source: raw capture for `aa_00792980` + live `decompile_function` / `read_memory` 2026-07-29.
- Prefer assembly when decompiler conflicts — prologue bytes seal field offs.
- `param_1` is `int* this` → index `N` means byte offset `N*4`.
- Do not treat this VA as the XML parser; that is `NDUIWindow_LoadInterfaceFile` `0x007b0ef0`.

## Prologue seals (`read_memory` @ `0x00792980`)

```
push ebx / ebp / esi
mov  esi, [esp+0x10]     ; path (stack arg after 3 pushes)
push esi                 ; arg for LoadInterfaceFile
mov  ebp, ecx            ; this
call NDUIWindow_LoadInterfaceFile   ; rel → 0x007b0ef0
mov  ecx, [ebp+0x4b4]    ; cached [0x12d]
xor  ebx, ebx
cmp  ecx, ebx
mov  [ebp+0x4b8], ebx    ; [0x12e] = 0
mov  [ebp+0x4bc], ebx    ; [0x12f] = 0
jz   skip_release
mov  eax, [ecx]
push 1
call [eax]               ; virtual release
cmp  esi, ebx            ; path == null?
mov  [ebp+0x4b4], ebx    ; clear cache
jnz  done_if_path_nonzero
; … null-path hash walk …
```

## Field / virtual map

| Location | Role |
|---|---|
| `this+0x4B4` `[0x12d]` | Owned sub-object*; released with vtbl[0](1) |
| `this+0x4B8` `[0x12e]` | Cleared companion |
| `this+0x4BC` `[0x12f]` | Cleared companion |
| `this+0x4C0` `[0x130]` | Hash root (null path) |
| `hash+0x1d` | Traversal lock byte |
| `hash/node+0x14` | Next-node chain |
| `node+0x8` | Child object* |
| `this` vtbl `+0x3d8` | May-walk children predicate |
| `this` vtbl `+0x34c` | Post-hide refresh |
| child vtbl `+0x28` | Hide / set-visible(0) style |

## Pseudocode (annotated)

```c
void __thiscall NDUIWindow_ReloadInterface(int *this, char *path)
{
  NDUIWindow_LoadInterfaceFile(path);           // always; may be null

  this[0x12e] = 0;  // +0x4B8
  this[0x12f] = 0;  // +0x4BC
  if (this[0x12d] != 0) {                       // +0x4B4
    (**(code **)this[0x12d])(1);                // release flag 1
  }
  this[0x12d] = 0;

  if (path != 0) return;                        // normal XML path ends

  // null path only
  if ((**(code **)(*this + 0x3d8))() && this[0x130]) {
    FUN_00411e10();                             // lock traversal
    // walk hash nodes; child->vtbl[+0x28](0)
    // unlock hash+0x1d; this->vtbl[+0x34c]()
  }
}
```

## Open questions

- Product names of vtbl `+0x3d8` / `+0x34c` / child `+0x28`.
- Full `LoadInterfaceFile` null-path semantics (out of unit).
- `FUN_00411e10` identity beyond hash lock.
