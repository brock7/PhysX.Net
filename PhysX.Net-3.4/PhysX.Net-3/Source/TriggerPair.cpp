#include "StdAfx.h"
#include "TriggerPair.h"
#include "Shape.h"

PxTriggerPair TriggerPair::ToUnmanaged(TriggerPair^ pair)
{
	ThrowIfNull(pair, "pair");

	PxTriggerPair tp;
		tp.otherShape = GetPointerOrNull(pair->OtherShape);
		tp.status = ToUnmanagedEnum(PxPairFlag, pair->Status);
		tp.triggerShape = GetPointerOrNull(pair->TriggerShape);

	return tp;
}
TriggerPair^ TriggerPair::ToManaged(PxTriggerPair pair)
{
	auto tp = gcnew TriggerPair();
		tp->OtherShape = ObjectTable::TryGetObject<Shape^>((intptr_t)pair.otherShape);
		tp->OtherActor = ObjectTable::TryGetObject<RigidActor^>((intptr_t)pair.otherActor);
		tp->Status = ToManagedEnum(PairFlag, pair.status);
		tp->TriggerShape = ObjectTable::TryGetObject<Shape^>((intptr_t)pair.triggerShape);
		tp->TriggerActor = ObjectTable::TryGetObject<RigidActor^>((intptr_t)pair.triggerActor);

	return tp;
}