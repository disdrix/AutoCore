# Annotated low-level: CNDHash_Insert

| Field | Value |
|---|---|
| Stable ID | `aa_0053c560` |
| VA | `0x0053c560` |
| System | container (continent unlock / create-packet callers) |
| Date | 2026-07-23; dual strengthen 2026-07-29 |

## Machine-level notes

- Source: raw capture for `aa_0053c560`; live + force decompile 2026-07-29 ≡ raw CF.
- `__thiscall(this=hash, key, value, allowDuplicate) → int`.
- `allowDuplicate`: **soft-skip-if-exists** (return 1, no mutation) — **not** multi-value insert. Known callers pass `'\0'`.
- Null value → `0x80004003` (`E_POINTER`; decompiler signed `-0x7fffbffd`).
- Hard duplicate → log + `0x80004005` (`E_FAIL`; signed `-0x7fffbffb`).
- Lock `this+0x1d`: log `"HashError:insert, already locked…"` + `"VOG_DEBUG_STOP"`; **continues**.
- Hash: `+8` mask, `+0xc` count, `+0x10` buckets*, `+0x14` listHead, `+0x18` listTail.
- Node 0x1c (slab `FUN_0053ada0`): vtbl `PTR_FUN_009cefd4`, `+4` touch, `+8` value, `+0xc` bkt next, `+0x10` key, `+0x14` list next, `+0x18` list prev.
- Bucket: `sentinel = buckets[key & mask]`; head-insert at `sentinel+4`; `FUN_00537d30` integrity walk.
- Twins (other dual owners): `FUN_0053c360` vtbl `009cf024`, `FUN_0053c660` vtbl `009cefe4`.
- Callers: UnlockContinentObject `char+0x534`; ApplyCreateFromPacket continent slots.

## Pseudocode (annotated copy of raw)

```c
/* Generic CNDHash insert(key, value). Used when applying CreateCharacterExtended continent slots
   and UnlockContinentObject. */

int __thiscall CNDHash_Insert(void *this,uint key,void *value,char allowDuplicate)
/* allowDuplicate = soft-skip-if-exists; not multi-insert */
{
  int iVar1;           /* bucket sentinel */
  void *pvVar2;        /* existing value from Lookup */
  undefined4 *puVar3;  /* new 0x1c node */
  
  if (value == (void *)0x0) {
    return -0x7fffbffd; /* 0x80004003 E_POINTER */
  }
  if (*(char *)((int)this + 0x1d) != '\0') { /* lockedForTraversal — warn only */
    FUN_007a4480(0,"HashError:insert, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  if (allowDuplicate != '\0') {
    pvVar2 = CNDHash_LookupByKey(this,key);
    if (pvVar2 != (void *)0x0) {
      return 1; /* soft: key present, no insert */
    }
  }
  pvVar2 = CNDHash_LookupByKey(this,key);
  if (pvVar2 != (void *)0x0) {
    FUN_007a4480(0,"Duplicate hash insert %u, failing out",key);
    return -0x7fffbffb; /* 0x80004005 E_FAIL */
  }
  puVar3 = (undefined4 *)FUN_0053ada0(); /* freelist pop 0x1c node; ECX freelist Open */
  puVar3[3] = 0;                         /* +0x0c bucketNext */
  *puVar3 = &PTR_FUN_009cefd4;            /* +0x00 vtbl (this family) */
  puVar3[5] = 0;                         /* +0x14 listNext */
  puVar3[6] = 0;                         /* +0x18 listPrev */
  *(undefined1 *)(puVar3 + 1) = 0;       /* +0x04 touch flag */
  puVar3[2] = value;                     /* +0x08 value* */
  puVar3[4] = key;                       /* +0x10 key */
  /* buckets[key & mask] → sentinel; head-insert at sentinel+4 */
  iVar1 = *(int *)(*(int *)((int)this + 0x10) + (*(uint *)((int)this + 8) & key) * 4);
  puVar3[3] = *(undefined4 *)(iVar1 + 4);
  *(undefined4 **)(iVar1 + 4) = puVar3;
  FUN_00537d30(); /* bucket-chain touch-flag integrity / repair */
  if (*(int *)((int)this + 0x18) != 0) { /* non-empty list: append at tail */
    *(undefined4 **)(*(int *)((int)this + 0x18) + 0x14) = puVar3;
    puVar3[5] = 0;
    puVar3[6] = *(undefined4 *)((int)this + 0x18);
    *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
    *(undefined4 **)((int)this + 0x18) = puVar3;
    return 0;
  }
  /* empty list: head = tail = new */
  *(undefined4 **)((int)this + 0x18) = puVar3;
  *(undefined4 **)((int)this + 0x14) = puVar3;
  puVar3[6] = 0;
  puVar3[5] = 0;
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  return 0;
}
```

## Open questions

- Freelist ECX / this-offset for `FUN_0053ada0`.
- Full CNDHash header before +0x08 (ctor, freelist embed).
- Node vtbl method table at `009cefd4`.
- Runtime / bit-exact verification.
